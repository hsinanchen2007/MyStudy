### 解题思路：动态规划
一道基础的动态规划题目
**思路**：dp数组`dp[i]`代表到第i号为止，最长总时长；
**初始化**：`dp[0] = nums[0];  
        dp[1] = max(nums[0], nums[1]);`
然后，从`i=2`开始，利用`dp[i-2]`和`dp[i-1]`计算当前最大值；
**规划思路**：第i号的最大值 = max(第i号不预约，第i号预约)，即`dp[i] = max(dp[i-1], dp[i-2]+nums[i])`;
最后返回`dp[nums.size()-1]`即可。
![image.png](https://pic.leetcode-cn.com/5f89545413b2387a43ed6695d61c90d0e02fcc4663a9faa1da76a263c013b810-image.png)

### 代码

```cpp
class Solution {
    //数组中选择不相邻的数，要求和最大
    //dp数组：目前为止的最大和；
    //dp思路：max(本次不预约，本次预约)，即max(dp[i-1], dp[i-2]+nums[i]);
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int> dp(n, 0); // initialize dp vector
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
```