#include "mystring.h"
#include <iostream>

using namespace std;
inline MyString::MyString(char const * cstr)
{
	if(cstr)
	{
		m_data = new char[strlen(cstr)+1];
		strcpy(m_data, cstr);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline MyString::~MyString()
{
	delete []m_data;
}

inline MyString::MyString(const MyString &ms)
{
	m_data = new char[strlen(ms.m_data)+1];
	strcpy(m_data, ms.m_data);
}
inline MyString MyString::operator=(const MyString& rhs)
{
	if(&rhs == this)
	{
		return *this;
	}
	else
	{
		delete[] m_data;
		m_data = new char[strlen(rhs.m_data)+1];
		strcpy(m_data, rhs.m_data);
		return *this;
	}
}

inline MyString MyString::operator=(const char* rhs)
{
	if(rhs)
	{
		delete[] m_data;
		m_data = new char[strlen(rhs)+1];
		strcpy(m_data, rhs);
		return *this;
	}
	else
	{
		delete[] m_data;
		m_data = new char[1];
		*m_data = '\0';
		return *this;
	}
}

ostream& operator<<(ostream& os, const MyString& rhs)
{
	return (os << rhs.get_c_str());
}


int main()
{
	MyString* ms = new MyString("123213");
	cout << ms->get_c_str() << endl;
	cout << *ms << endl;
	MyString ms2(*ms);
	cout << ms2 << endl;
	MyString ms3;
	ms3 = "Hello, world";
	ms2 = ms3;
	cout << ms3 << endl;
	cout << ms2 << endl;
	return 0;
}
           
