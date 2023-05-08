/* Compiler Theory and Design
   Duane J. Jarc 
*/

%{

#include <string>
#include <vector>
#include <map>

using namespace std;
#include <iostream>
#include "types.h"
#include "listing.h"
#include "symbols.h"

int yylex();
void yyerror(const char* message);

Symbols<Types> symbols;

%}

%error-verbose

%union
{
	CharPtr iden;
	Types type;
}

%token <iden> IDENTIFIER
%token <type> INT_LITERAL BOOL_LITERAL REAL_LITERAL
%token ADDOP MULOP RELOP ANDOP REMOP OROP EXPOP NOTOP
%token BEGIN_ BOOLEAN END ENDREDUCE FUNCTION INTEGER IS REDUCE RETURNS
%token ARROW CASE ELSE ENDCASE ENDIF IF OTHERS REAL THEN WHEN 

%type <type> type statement statement_ reductions expression relation term
	factor primary and exponent not function_header body variable case

%%

function:	
	function_header optional_variable body {checkReturns($3);}
	;
	
function_header:	
	FUNCTION IDENTIFIER optional_parameters RETURNS type ';' {getExpected($5);} // EXPECTED RETURN
	| error ';' {$$ = MISMATCH;}
	;

optional_variable:
	optional_variable variable 
	|
	;

variable:
	IDENTIFIER ':' type IS statement_ {checkAssignment($3, $5, "Variable Initialization");
		if (!symbols.find($1, $3)) symbols.insert($1, $3); else {appendError(DUPLICATE_IDENTIFIER, $1);};}
	| error ';' {$$ = MISMATCH;}
	;

optional_parameters:
	params
	|
	;

params:
	params ',' parameter 
	| parameter 
	;

parameter:
	IDENTIFIER ':' type
	;

type:
	INTEGER {$$ = INT_TYPE;} |
	BOOLEAN {$$ = BOOL_TYPE;} |
	REAL {$$ = REAL_TYPE;}
	;

body:
	BEGIN_ statement_ END ';' {$$ = $2;};
    
statement_:
	statement ';' {$$ = $1;} |
	error ';' {$$ = MISMATCH;} ;
	
statement:
	expression {$$ = $1;}
	| REDUCE operator reductions ENDREDUCE {$$ = $3;}
	| IF expression THEN statement_ ELSE statement_ ENDIF {$$ = checkIfElseStatement($2, $4, $6); }
	| CASE expression  IS case OTHERS ARROW statement_ ENDCASE {checkExpression($2);}
	 ;

case: 
	case WHEN INT_LITERAL ARROW statement_ {$$ = $5;}
	| error ';'
	|
	; 

operator:
	ADDOP 
	| MULOP 
	;

reductions:
	reductions statement_ {$$ = checkArithmetic($1, $2);}
	| {$$ = INT_TYPE;}
	;
		    
expression:
	expression OROP and {$$ = checkLogical($1, $3);}
	| and ;

and:
	and ANDOP relation {$$ = checkLogical($1, $3);}
	| relation
	;

relation:
	relation RELOP term {$$ = checkRelational($1, $3);}|
	term
	;

term:
	term ADDOP factor {$$ = checkArithmetic($1, $3);}|
	factor ;
      
factor:
	factor MULOP exponent {$$ = checkArithmetic($1, $3);}|
	factor REMOP exponent {$$ = checkInt($1, $3);}|
	exponent 
	;

exponent:
	not |
	not EXPOP primary {$$ = checkArithmetic($1, $3);};

not:
	NOTOP not {$$ = checkNot($2);} | 
	primary
	;

primary:
	'(' expression ')' {$$ = $2;}|
	INT_LITERAL | 
	REAL_LITERAL |
	BOOL_LITERAL | 
	IDENTIFIER {if (!symbols.find($1, $$)) appendError(UNDECLARED, $1);}
	;
    
%%

void yyerror(const char* message)
{
	appendError(SYNTAX, message);
}

int main(int argc, char *argv[])    
{
	firstLine();
	yyparse();
	lastLine();
	return 0;
} 
