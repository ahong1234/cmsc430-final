/*  
	Compiler Theory and Design
    Duane J. Jarc 
    Alex Hong 
	CMSC 430 Project 4
	Due : 5/9/23
*/

typedef char* CharPtr;

enum Types {MISMATCH, INT_TYPE, BOOL_TYPE, REAL_TYPE};

void checkAssignment(Types lValue, Types rValue, string message);
Types checkArithmetic(Types left, Types right);
Types checkLogical(Types left, Types right);
Types checkRelational(Types left, Types right);
Types checkNot(Types type);
Types checkInt(Types left, Types right);
Types checkIfElseStatement(Types ifStatement, Types ifResult, Types elseResult);
void getExpected(Types expected);
void checkReturns(Types actual);
void checkExpression(Types caseExpression);