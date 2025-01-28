// https: // leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <map>
#define nl '\n'
using namespace std;

// ============================================ O(n^2) ============================================
// class Solution
// {
//     int getIndex(vector<int> &nums, int value, int startIndex)
//     {
//         int answer = -1;
//         for (int i = startIndex; i < nums.size(); i++)
//         {
//             if (nums[i] == value)
//             {
//                 answer = i;
//                 break;
//             }
//         }
//         return answer;
//     }

// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         vector<int> answer = {0, 1};
//         int otherIndex;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             otherIndex = getIndex(nums, (target - nums[i]), i + 1);
//             if (otherIndex != -1)
//             {
//                 answer[0] = i;
//                 answer[1] = otherIndex;
//                 break;
//             }
//         }
//         return answer;
//     }
// };

// ============================================ O(n) ============================================
class Solution
{

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> answer = {0, 1};
        int complement;
        map<int, int> indexes;

        for (int i = 0; i < nums.size(); i++)
        {
            complement = target - nums[i];
            if (indexes.count(complement) > 0)
            {
                answer[0] = i;
                answer[1] = indexes[complement];
                break;
            }
            else
            {
                indexes[nums[i]] = i;
            }
        }
        return answer;
    }
};

int main()
{
    vector<int> test = {
        3, 2, 4};

    Solution s;

    for (int i : s.twoSum(test, 6))
        cout << i << nl;

  

    return 0;
}