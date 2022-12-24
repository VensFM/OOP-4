#pragma once
#include <cstddef>
#include <iostream>

class String
{
public:
	String();
	String(const char* str);
	String(const String& str);
	String(String&& str) noexcept;
	~String();

	size_t getSize()const;
	char* getString()const;
	String& operator = (const char* str);
	String& operator = (String&& str) noexcept;
	char& operator [] (size_t pos)const;
	String& insert (size_t pos, const char* str);
	int compare (const String& str)const;
	size_t rfind(const char* str, size_t pos, size_t n) const;
	String& erase(size_t pos, size_t len);
	friend std::ostream& operator << (std::ostream& stream, const String& str);
private:
	size_t size;
	const size_t capacity = 8;
	char* ptr;
};