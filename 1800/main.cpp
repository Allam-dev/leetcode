#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

class Solution
{
public:

    // O(n)
    int maxAscendingSum(vector<int> &nums)
    {
        int lastSum = 0;
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                if (currentSum > lastSum)
                    lastSum = currentSum;

                currentSum = nums[i];
            }
            else
                currentSum += nums[i];
        }
        if (currentSum > lastSum)
            return currentSum;
        else
            return lastSum;
    }
};

int main()
{
    vector<int> inputs;
    int n;
    cin >> n;

    while (n > 0)
    {
        inputs.push_back(n);
        cin >> n;
    }

    Solution s;
    cout << s.maxAscendingSum(inputs) << nl;
}