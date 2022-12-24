#include "String.h"

String::String()
{
	size = 0;
	ptr = new char[1];
	ptr[0] = '\0';
}
String::String(const char* str)
{
	size = strlen(str);
	ptr = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = str[i];
	}
	ptr[size] = '\0';
}
String::String(const String& str)
{
	size = str.size;
	ptr = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = str.ptr[i];
	}
	ptr[size] = '\0';
}
String::String(String&& str) noexcept
{
	size = str.size;
	ptr = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = str.ptr[i];
	}
	ptr[size] = '\0';
	delete[] str.ptr;
	str.ptr = nullptr;
	str.size = 0;
}
String::~String()
{
	if (ptr != nullptr)
	{
		delete[] ptr;
	}
}

size_t String::getSize()const
{
	return size;
}

char* String::getString()const
{
	return ptr;
}

String& String::operator = (const char* str)
{
	if (ptr != nullptr)
	{
		delete[] ptr;
	}
	size = strlen(str);
	ptr = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = str[i];
	}
	ptr[size] = '\0';
	return *this;
}

String& String::operator = (String&& str) noexcept
{
	if (ptr != nullptr)
	{
		delete[] ptr;
	}
	size = str.size;
	ptr = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = str.ptr[i];
	}
	ptr[size] = '\0';
	delete[] str.ptr;
	str.ptr = nullptr;
	str.size = 0;
	return *this;
}

char& String::operator [] (size_t pos)const
{
	if (pos > size)
	{
		std::cerr << "	Position exceeds string size\n";
		return ptr[size];
	}
	return ptr[pos];
}

String& String::insert(size_t pos, const char* str)
{
	if (pos > size)
	{
		std::cerr << "	You are out of line\n";
		return *this;
	}
	size_t lenth = strlen(str);
	String buf = std::move(*this);
	size = buf.size + lenth;
	ptr = new char[size + 1];
	for (size_t i = 0; i < pos; ++i)
	{
		ptr[i] = buf.ptr[i];
	}
	for (size_t i = pos; str[i - pos] != '\0'; ++i)
	{
		ptr[i] = str[i - pos];
	}
	for (size_t i = pos + lenth; buf.ptr[i - lenth] != '\0'; ++i)
	{
		ptr[i] = buf.ptr[i-lenth];
	}
	ptr[size] = '\0';
	return *this;
}

int String::compare(const String& str)const
{
	size_t i;
	for (i = 0; ptr[i] != '\0' && str.ptr[i] != '\0'; ++i)
	{
		if (ptr[i] < str.ptr[i])
		{
			return -1;
		}
		if (ptr[i] > str.ptr[i])
		{
			return 1;
		}
	}
	if (ptr[i] == '\0' && str.ptr[i] == '\0')
	{
		return 0;
	}
	if (ptr[i] != '\0')
	{
		return 1;
	}
	return -1;
}

size_t String::rfind(const char* str, size_t pos, size_t n) const
{
	if (str == nullptr|| strlen(str) == 0)
	{
		std::cerr << "	Searched string does not exist ";
		return size;
	}
	if (strlen(str) < n)
	{
		std::cerr << "	Search string doesn't have that many characters ";
		return size;
	}
	if (pos + n > size)
	{
		std::cerr << "	You are out of line ";
		return size;
	}
	size_t buf = size + 1;
	bool flag;
	for (size_t i = pos; i <= size - n; ++i)
	{
		flag = true;
		for (size_t j = i; j < i + n; ++j)
		{
			if (ptr[j] != str[j - i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			buf = i;
		}
	}
	if (buf > size)
	{
		return size;
	}
	return buf;
}

String& String::erase(size_t pos, size_t len)
{
	if (pos + len > size)
	{
		std::cerr << "	You are out of line\n";
		return *this;
	}
	String buf = std::move(*this);
	size = buf.size - len;
	ptr = new char[size + 1];
	for (size_t i = 0; i < pos; ++i)
	{
		ptr[i] = buf.ptr[i];
	}
	for (size_t i = pos + len; buf.ptr[i] != '\0'; ++i)
	{
		ptr[i - len] = buf.ptr[i];
	}
	ptr[size] = '\0';
	return *this;
}

std::ostream& operator << (std::ostream& stream, const String& str)
{
	if (str.ptr == nullptr)
	{
		return stream;
	}
	for (size_t i = 0; i < str.size; ++i)
	{
		stream << str.ptr[i];
	}
	return stream;
}