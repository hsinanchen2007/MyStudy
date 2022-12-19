1.BFS超时最后一个用例超时
2.使用DP
3.从当前点达到的最远距离如果是目的地则Pass
4.计算从在当前位置可以走到最远的距离
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/09/24
*/
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.empty() || nums.size() == 1) {
            return true;
        }
        if (nums.at(0) == 0) {
            return false;
        }

        int dp[nums.size() + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            goFarAwayFromMe(dp, i, nums);
            if (stayWithMe(dp, i) && finished(i, nums)) {
                return false;
            }
        }
        return sayGoodBye(dp, nums);
    }

    bool sayGoodBye(int * dp, vector<int> &nums)
    {
        if (dp[nums.size()] >= nums.size() - 1) {
            return true;
        }
        return false;
    }

    void goFarAwayFromMe(int * dp, int i, vector<int>& nums)
    {
        dp[i + 1] = max(dp[i], i + nums[i]); //在一步是否可以达到和走一步算一步中选择
    }

    bool stayWithMe(int *dp, int i)
    {
        return dp[i + 1] == i;
    }

    bool finished(int i, vector<int> &nums)
    {
        return i != nums.size() - 1;
    }

};
```
