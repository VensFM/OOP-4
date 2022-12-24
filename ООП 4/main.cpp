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
void testSort();
void complexTest();
void sort(String* arr, size_t N);


int main()
{
	cout << "		OOP-4\n";
	globalTest();
	return 0;
}

void globalTest()
{
	testMoveConstructor();
	testOperatorWithCString();
	testMoveOperator();
	testSquareBrackets();
	testInsert();
	testCompare();
	testRfind();
	testErase();
	testSort();
	complexTest();
}

void testMoveConstructor()
{
	String str1 = "abcd";
	cout << "\n	Test move constructor:\nBefore:\n String1: " << str1 << "\n String2: Not yet announced\nAfter:\n";
	String str2 = std::move(str1);
	cout << " String1: " << str1 << "\n String2: " << str2 << "\n";
}

void testOperatorWithCString()
{
	String str1 = "abcd";
	cout << "\n	Test operator = with C string:\nBefore:\n String: " << str1 << "\nAfter str = dcba:\n String: ";
	str1 = "dcba";
	cout << str1 << "\n";
}

void testMoveOperator()
{
	String str1("abcd");
	String str2("dcba");
	cout << "\n	Test move operator:\nBefore:\n String1: " << str1 << "\n String2: " << str2 << "\nAfter:\n";
	str2 = std::move(str1);
	cout << " String1: " << str1 << "\n String2: " << str2 << "\n";
}

void testSquareBrackets()
{
	String str("abcdefg");
	cout << "\n	Test square brackets:\nString: " << str << "\n";
	size_t i;
	for (i = 0; str[i] != '\0'; ++i)
	{
		cout << " String[" << i << "]: " << str[i] << "\n";
	}
	cout << "If you look outside the array:\n String[" << i + 1 << "]: ";
	cout << str[i + 1];
}

void testInsert()
{
	String str1("11111111112222222222");
	String str2("|insert was here|");
	cout << "\n	Test insert:\nBefore:\n String1: " << str1 << "\n String2: " << str2 << "\n";
	str1.insert(str1.getSize(), str2.getString());
	str1.insert(10, str2.getString());
	str1.insert(0, str2.getString());
	cout << "After:\n String1: " << str1 << "\n String2: " << str2 << "\n";
}

void testCompare()
{
	String str("5555"), str1("1111"), str2(str), str3("9999");
	cout << "\n	Test compare:\n String1: " << str << "\n String2: " << str1 << "\n String3: " << str2 << "\n String2: " << str3 << "\n";
	cout << "Compare string1 and string2: " << str.compare(str1) << "\n";
	cout << "Compare string1 and string3: " << str.compare(str2) << "\n";
	cout << "Compare string1 and string4: " << str.compare(str3) << "\n";
}

void testRfind()
{
	String str("abcdefg"), str1;
	cout << "\n	Test rfind:\nString: " << str << "\n";
	cout << " When looking for an empty string: ";
	cout << str.rfind(str1.getString(), 0, 1)<<"\n";
	cout << " If the search string is less than n: ";
	cout << str.rfind("123", 0, 4) << "\n";
	cout << " If you go beyond the line: ";
	cout << str.rfind("123", 6, 3) << "\n";
	cout << " If the search string is not found: ";
	cout << str.rfind("123", 0, 3) << "\n";
	cout << " If everything is okay: ";
	cout << str.rfind("c", 0, 1) << "\n";
}

void testErase()
{
	String str("123456789");
	cout << "\n	Test erase:\nString: " << str<<"\n";
	str.erase(str.getSize() - 1, 1);
	cout << " Removing the last character: " << str << "\n";
	str.erase(0, 1);
	cout << " Removing the first character: " << str << "\n";
	str.erase((str.getSize() / 2), 1);
	cout << " Removing the midle character: " << str << "\n";
}

void testSort()
{
	String* arr = new String[5];
	String str("aaaaa");
	cout << "\n	Test sort:\nBefore:\n";
	for (size_t i = 0; i < 5; ++i)
	{
		arr[i] = str.getString();
		cout <<" "<< i + 1 << ") " << arr[i] << "\n";
		str.erase(0, 1);
	}
	sort(arr, 5);
	cout << "After:\n";
	for (size_t i = 0; i < 5; ++i)
	{
		cout << " " << i + 1 << ") " << arr[i] << "\n";
	}
	delete[] arr;
}

void complexTest()
{
	String* arr = new String[5];
	String str("delete"), str1("aaaaa");
	cout << "\n	Complex test:\nBefore:\n";
	for (size_t i = 0; i < 5; ++i)
	{
		arr[i] = str1.getString();
		if ((i + 1) % 2 == 0)
		{
			arr[i].insert(0, str.getString());
		}
		if ((i + 1) % 2 == 1)
		{
			arr[i].insert(arr[i].getSize(), str.getString());
		}
		cout << " " << i + 1 << ") " << arr[i] << "\n";
		str1.erase(0, 1);
	}
	cout << "After:\n";
	size_t count = 0;
	for (size_t i = 0; i < 5; ++i)
	{
		size_t buf = arr[i].rfind(str.getString(), 0, str.getSize());
		if (buf == 0)
		{
			++count;
		}
		if (buf != 0 && buf != arr[i].getSize())
		{
			arr[i].erase(buf, str.getSize());
		}
		cout << " " << i + 1 << ") " << arr[i] << "\n";
	}
	cout << " Number of lines starting with the search string: " << count;
	delete[] arr;
}

void sort(String* arr, size_t N)
{
	String buf;
	for (size_t i = 0; i < N - 1; ++i)
	{
		for (size_t j = N - 1; j > i; --j)
		{
			if (arr[j].compare(arr[j-1]) < 0)
			{
				buf = arr[j].getString();
				arr[j] = arr[j - 1].getString();
				arr[j - 1] = buf.getString();
			}
		}
	}
}
