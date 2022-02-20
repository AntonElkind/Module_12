#include <iostream>
#include "sort.h"

using namespace std;

bool IsKPeriodic(const string& txt, int k);

int main()
{
	cout << "HW Module 12" << endl;

	string txt = "abcabcabcabc";
	int k = 3;

	if (IsKPeriodic(txt, k))
	{
		cout << "Periodic" << endl;
	}
	else
	{
		cout << "Not periodic" << endl;
	}

	return 0;
}

bool IsKPeriodic(const string& txt, int k)
{
	if (k < 1)
	{
		return false;
	}

	string pat = txt.substr(0, k);
	int found = KMPSearch(pat, txt);
	
	if (found * k == txt.length())
	{
		return true;
	}
	return false;
}