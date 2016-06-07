#define _CRT_SECURE_NO_WARNINGS
 #include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	String()
		:_pstr(new char[1])
		, _pcount(new int(1))
	{
		*_pstr = '\0';
	}
	String(char *pstr)
	{
		if (pstr == NULL)
		{
			_pstr = new char[1];
			*_pstr = '\0';
        }
		else
		{
			_pstr = new char[strlen(pstr) + 1];
			strcpy(_pstr, pstr);
			_pcount = new int(1);
		}
		
	}
	String(const String &s)
		:_pstr(s._pstr)
		, _pcount(s._pcount)
	{
		(*_pcount)++;
	}
	String &operator=(const String& s)
	{
		if (this != &s)
		{
			--(*_pcount);
			if ((*_pcount) == 0)
			{
				delete []_pstr;
				delete _pcount;
			}
			else
			{
				_pstr = s._pstr;
				_pcount = s._pcount; 
				(*_pcount)++;
			}		
		}
		return *this;
	}
	~String()
	{
		assert(_pstr);
		assert(_pcount);
		--(*_pcount);
		if (*_pcount == 0)
		{
			delete[] _pstr;
			_pstr = NULL;
			delete _pcount;
			_pcount = NULL;
		}

	}
	 

private :
	char* _pstr;
	int* _pcount; 
};

int main()
{
	String s1;
	String s2("aa");
	String s3(s2);
	s1 = s2;
	return 0;
}