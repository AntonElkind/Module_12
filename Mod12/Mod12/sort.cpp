#include "sort.h"
#include <iostream>

void computeLPS(std::string pat, int* lps)
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size())
    {
        if (pat[i] == pat[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) 
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const std::string& pat, const std::string& txt)
{
    int* lps = new int[pat.size()];

    computeLPS(pat, lps);

    int patternCounter = 0;
    int i = 0;
    int j = 0;
    while (i < txt.size())
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size())
        {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
            patternCounter++;
        }
        else if (i < txt.size() && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    delete[] lps;
    return patternCounter;
}