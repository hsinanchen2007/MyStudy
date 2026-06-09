```
/*
    之前写出了 dp[i] = max(dp[i - 1] * nums[i], nums[i]) 状态转移方程
    但是存在一个问题，当num[i + 1]是负数时，dp[i]最小，dp[i + 1]才是最大值
    所以应该再有一个DP_MIN数组，来记录以index为i结尾的连续数组的最小值

    dpA -> MaxDP
    dpB -> MinDP
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>dpA(nums.size());
        vector<int>dpB(nums.size());

        dpA[0]  = nums[0];
        dpB[0]  = nums[0];
        int Max = dpA[0]; 

        for(int i = 1; i < nums.size(); ++i){
            dpA[i] = max(nums[i], max(dpA[i - 1] * nums[i], dpB[i - 1] * nums[i]));
            dpB[i] = min(nums[i], min(dpA[i - 1] * nums[i], dpB[i - 1] * nums[i]));
            Max = max(dpA[i], Max);
        }

        return Max;
    }
};
```


