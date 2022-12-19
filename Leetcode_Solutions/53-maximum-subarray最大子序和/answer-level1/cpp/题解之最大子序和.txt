### 解题思路
此处撰写解题思路
这是动态规划的经典问题。

首先用dp[i]数组表示以 nums[i] 为结尾的子数组的最大和，它必包含元素nums[i]

那么dp[i]等于什么，即它的状态转移方程是什么？
1：只有一个元素，dp[i] = nums[i];
2: 有多个元素，即除末尾元素nums[i],还包含着以nums[i - 1]元素结尾的子数组的最大和,所以dp[i] = dp[i - 1] + nums[i]; 
所以dp[i] = max(1, 2);

那么其最大和又是多少？
我们只需遍历一遍dp[i]数组，求其最大值即可。

由上述则可发现对左端点的枚举是没有必要的。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        int dp[N];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];        // 设置边界

        for(int i = 1; i < nums.size(); i ++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);  //状态转移方程
        }
        int k = 0;
        for(int i = 1; i < nums.size(); i ++ )
        {
            if(dp[i] > dp[k])   k = i;
        }

        
        return dp[k];
    }
};
```