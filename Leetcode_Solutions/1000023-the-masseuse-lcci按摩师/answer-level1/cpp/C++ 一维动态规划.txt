### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution
{
public:
    int massage(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        //由于后面存在dp[1]dp[2]赋值的情况所以，必须要考虑到数组越界的情况（没考虑到的情况）
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for(int i= 3; i <= n; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            //第一二天人为设定，后面的天数由之前的决定，如果当天接受预约，
            //说明只能+前天的时长，如果当天不接受预约，说明要加昨天的时长）
        }
        return dp[n];
    }
};
```