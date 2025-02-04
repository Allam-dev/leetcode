#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

class Solution
{
private:
    map<char, int> symbols = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    // int romanToInt(string s)
    // {
    //     int sum = 0;
    //     bool isLastIndex = false;
    //     int nextIndex = 0;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         nextIndex = i + 1;
    //         isLastIndex = (i == s.size() - 1);
    //         if (s[i] == 'I' && !isLastIndex && (s[nextIndex] == 'V' || s[nextIndex] == 'X'))
    //         {
    //             sum += (symbols[s[nextIndex]] - symbols[s[i]]);
    //             i++;
    //         }
    //         else if (s[i] == 'X' && !isLastIndex && (s[nextIndex] == 'L' || s[nextIndex] == 'C'))
    //         {
    //             sum += (symbols[s[nextIndex]] - symbols[s[i]]);
    //             i++;
    //         }
    //         else if (s[i] == 'C' && !isLastIndex && (s[nextIndex] == 'D' || s[nextIndex] == 'M'))
    //         {
    //             sum += (symbols[s[nextIndex]] - symbols[s[i]]);
    //             i++;
    //         }
    //         else
    //         {
    //             sum += symbols[s[i]];
    //         }
    //     }
    //     return sum;
    // }

    // better syntax, but the first is faster
    int romanToInt(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (symbols[s[i]] < symbols[s[i + 1]])
                sum -= symbols[s[i]];
            else

                sum += symbols[s[i]];
        }
        return sum + symbols[s.back()];
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.romanToInt(s) << nl;
}