/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INT_LITERAL = 259,
     BOOL_LITERAL = 260,
     REAL_LITERAL = 261,
     ADDOP = 262,
     MULOP = 263,
     RELOP = 264,
     ANDOP = 265,
     REMOP = 266,
     OROP = 267,
     EXPOP = 268,
     NOTOP = 269,
     BEGIN_ = 270,
     BOOLEAN = 271,
     END = 272,
     ENDREDUCE = 273,
     FUNCTION = 274,
     INTEGER = 275,
     IS = 276,
     REDUCE = 277,
     RETURNS = 278,
     ARROW = 279,
     CASE = 280,
     ELSE = 281,
     ENDCASE = 282,
     ENDIF = 283,
     IF = 284,
     OTHERS = 285,
     REAL = 286,
     THEN = 287,
     WHEN = 288
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT_LITERAL 259
#define BOOL_LITERAL 260
#define REAL_LITERAL 261
#define ADDOP 262
#define MULOP 263
#define RELOP 264
#define ANDOP 265
#define REMOP 266
#define OROP 267
#define EXPOP 268
#define NOTOP 269
#define BEGIN_ 270
#define BOOLEAN 271
#define END 272
#define ENDREDUCE 273
#define FUNCTION 274
#define INTEGER 275
#define IS 276
#define REDUCE 277
#define RETURNS 278
#define ARROW 279
#define CASE 280
#define ELSE 281
#define ENDCASE 282
#define ENDIF 283
#define IF 284
#define OTHERS 285
#define REAL 286
#define THEN 287
#define WHEN 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "parser.y"
{
	CharPtr iden;
	Types type;
}
/* Line 1529 of yacc.c.  */
#line 120 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

