#include "String.h"

using std::cout;

void globalTest();
void testMoveConstructor();
void testOperatorWithCString();
void testMoveOperator();
void testSquareBrackets();
void testInsert();
void testCompare();
void testRfind();
void testErase();

int main()
{
	cout << "		OOP-4\n";
	globalTest();
	return 0;
}

void globalTest()
{
	testMoveConstructor();
	/*testOperatorWithCString();
	testMoveOperator();
	testSquareBrackets();
	testInsert();
	testCompare();
	testRfind();
	testErase();*/
}

void testMoveConstructor()
{
	String str1 = "abcd";
	cout << "	Test move constructor:\nBefore:\n String1: " << str1 << "\n String2: Not yet announced\nAfter:\n";
	String str2 = std::move(str1);
	cout << " String1: " << str1 << "\n String2: " << str2 << "\n";
}
