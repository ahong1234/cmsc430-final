// Compiler Theory and Design
// Duane J. Jarc

// This file contains the bodies of the type checking functions

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "types.h"
#include "listing.h"
Types expectedType;


void checkAssignment(Types lValue, Types rValue, string message)
{	
	if (lValue != MISMATCH && rValue != MISMATCH) {
		if (lValue == BOOL_TYPE && rValue != lValue) {
			appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
		}
		if (rValue == BOOL_TYPE && lValue != rValue) {
			appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
		}
		if (lValue == INT_TYPE && rValue == REAL_TYPE) {
			appendError(GENERAL_SEMANTIC, "Illegal Narrowing Variable Initialization");
		}
	}
}

Types checkArithmetic(Types left, Types right)
{
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == BOOL_TYPE || right == BOOL_TYPE)
	{
		appendError(GENERAL_SEMANTIC, "Numeric Type Required");
		return MISMATCH;
	}
	if ((left == REAL_TYPE && right == INT_TYPE) || (left == INT_TYPE && right == REAL_TYPE))
        return REAL_TYPE;
	return INT_TYPE;
}


Types checkLogical(Types left, Types right)
{
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left != BOOL_TYPE || right != BOOL_TYPE)
	{
		appendError(GENERAL_SEMANTIC, "Boolean Type Required");
		return MISMATCH;
	}	
		return BOOL_TYPE;
	return MISMATCH;
}

Types checkRelational(Types left, Types right)
{
	if (checkArithmetic(left, right) == MISMATCH)
		return MISMATCH;
	return BOOL_TYPE;
}

Types checkNot(Types type) {
	if (type != BOOL_TYPE) // the operand must be a boolean value
		appendError(GENERAL_SEMANTIC, "Boolean Type Required");
		return MISMATCH;
	return BOOL_TYPE;
}


Types checkInt(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if(left != INT_TYPE || right != INT_TYPE) // check to see if "left" and "right" are integer type
		appendError(GENERAL_SEMANTIC, "Remainder Operator Requires Integer Operands");
		return MISMATCH;
	return INT_TYPE;
}

Types checkIfElseStatement(Types ifStatement, Types ifResult, Types elseResult) { 
	if (ifStatement != BOOL_TYPE) {  // the IF condition needs to be a boolean type
		appendError(GENERAL_SEMANTIC, "If Expression Must Be Boolean");	
	}
	if (ifResult != elseResult) { // the if and else blocks must return same type
		appendError(GENERAL_SEMANTIC, "If-Then Type Mismatch"); // throw error if types do not match
	}
	return ifResult; // if the if and else block have the same return types then return the if block's type
	
}

void getExpected(Types expected) {
	expectedType = expected;
}

void checkReturns(Types actual) { 
	// cout << "expected: " << expectedType << "\nactual: " << actual << endl;
	if (expectedType == INT_TYPE && actual == REAL_TYPE) {
		appendError(GENERAL_SEMANTIC, "Illegal Narrowing Function Return\n");
	}
	if (expectedType == BOOL_TYPE && actual != expectedType) {
		appendError(GENERAL_SEMANTIC, "Type Mismatch on Function Return\n");
	}
	if (actual == BOOL_TYPE && expectedType != actual) {
		appendError(GENERAL_SEMANTIC, "Type Mismatch on Function Return\n");
	}
	
}

void checkExpression(Types caseExpression) {
	if (caseExpression != INT_TYPE) {
		appendError(GENERAL_SEMANTIC, "Case Expression Not Integer");
	}
}