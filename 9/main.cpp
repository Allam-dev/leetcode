#include <iostream>
#define nl '\n'
using namespace std;

class Solution
{
public:
    // O(log(x))
    // bool isPalindrome(int x)
    // {
    //     if (x < 0)
    //         return false;

    //     int tmpX = x
    // long reversedX = 0;

    //     while (tmpX)
    //     {
    //         reversedX = (reversedX * 10) + (tmpX % 10);
    //         tmpX /= 10;
    //     }

    //     return (x == reversedX);
    // }


// also O(log(x)) with O(1) for numbers between 0 and 10
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        else if (x < 10)
            return true;
        
        else
        {
            int tmpX = x;
            long reversedX = 0;

            while (tmpX)
            {
                reversedX = (reversedX * 10) + (tmpX % 10);
                tmpX /= 10;
            }

            return (x == reversedX);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    if (s.isPalindrome(n))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}