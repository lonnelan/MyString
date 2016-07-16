#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class MyString
{
private:
	char *m_data;
public:
	MyString(char const * cstr = 0);
	MyString(const MyString&);
	MyString operator= (const MyString&);
	~MyString();
	MyString operator= (const char* );
	char* get_c_str() const { return m_data; }
};



#endif //__MYSTRING_H__
