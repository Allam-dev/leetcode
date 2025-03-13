#include <bits\stdc++.h>

#define nl '\n'
using namespace std;

class Solution
{

    bool isPrime(int num)
    {
        if (num < 2)
        {
            return false;
        }

        for (int i = 2; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> ans = {-1, -1};
        int lastPrime = 0, smallestDiffrance = INT_MAX, diffrance = 0;
        if (left <= 2 && right >= 3)
        {
            ans[0] = 2;
            ans[1] = 3;
            return ans;
        }

        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
            {
                if (lastPrime == 0)
                    lastPrime = i;
                else
                {
                    diffrance = i - lastPrime;
                    if (diffrance == 2)
                    {
                        ans[0] = lastPrime;
                        ans[1] = i;
                        return ans;
                    }
                    else if (diffrance < smallestDiffrance)
                    {
                        smallestDiffrance = diffrance;
                        ans[0] = lastPrime;
                        ans[1] = i;
                    }
                    lastPrime = i;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int l, r;
    cin >> l >> r;
    Solution sol = Solution();
    for (auto i : sol.closestPrimes(l, r))
        cout << i << nl;
}