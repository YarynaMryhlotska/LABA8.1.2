#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* str, const char c, const char k, int i)
{
	if ((c == str[i] && k == str[i + 1])||
		(k == str[i] && c == str[i + 1]))
		return 1;
	if (str[i] != '\0')
		return Include(str, c, k, i + 1);
	else
		return 0;
}
char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 1] != 0)
	{
		if ((str[i] == 'S' && str[i + 1] == 'Q') ||
			(str[i] == 'Q' && str[i + 1] == 'S'))
		{
			strcat(t, "***");
			return Change(dest, str, t + 3, i + 2);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	
	char c = 'Q';
	char k = 'S';
	if (Include(str, c, k, 0))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}
