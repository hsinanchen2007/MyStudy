第一次写题解，想想都觉得蛮激动的呢，哈哈哈！
本题求整型数组中子数组和的最大值，其中整形数组为nums，并假设数组有n+1个元素，即nums[0]...nums[n]。
设想，无论我们最终要求的和最大的子数组长什么样，始终有一点可以确定的是任何形式的子数组的末尾位置元素一定是nums数组元素的其中之一。
基于上述想法，我们假设dp[i]表示以nums[i]结尾的的子数组的和的最大值，因此当我们知道dp[0]...dp[n]时，对于nums数组的和的最大值子即为max(dp[0]...dp[n])，因为nums中任何形式的子数组都逃不过以num[i]结尾的真香定律，那么和最大的子数组必然在以这n+1个值结尾的子数组其中，因此求一次max就ok了！！！
因此，可以想到状态转移方程为 dp[n] = max(dp[n-1] + nums[n], nums[n]);
那么，最终整形数组中子数组的和的最大值为 Vmax = max(dp[0], dp[1], ..., dp[n]);
代码如下：
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int size = nums.size();
        vector<int> dp(size, 0);
        if (size == 0) return 0;
        dp[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
        }
        
        for (int i = 0; i < size; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```
以上。
第一次写题解可能讲的不是很清楚，还请各位看官见谅！