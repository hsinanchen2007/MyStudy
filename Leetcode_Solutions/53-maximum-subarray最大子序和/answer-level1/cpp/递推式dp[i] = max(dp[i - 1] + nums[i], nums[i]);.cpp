### 解题思路
因为题目要求是连续的区间，所以说针对每一个元素，有两种情况：第一，把这个元素并入它之前最优的区间之中，第二，把这个元素单独作为一个新区间的开始，舍弃之前的区间。如果之前取好的区间还没有当前这个元素的值大，那么就舍弃之前的区间。在这个过程中用变量维护最大值。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size() + 1];
        dp[0] = nums[0];
        int maxx = dp[0];
        for(int i = 1 ; i < nums.size() ; ++i)
        {   
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(dp[i] > maxx)
            maxx = dp[i];
        }
        return maxx;
    }
};
```