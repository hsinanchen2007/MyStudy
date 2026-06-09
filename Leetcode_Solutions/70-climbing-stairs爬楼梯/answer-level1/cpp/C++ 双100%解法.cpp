### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/6cd3edad240bfff1f0bcd5bae6be93b9980cdc81976d4798d94449bee17fad9d-%E6%8D%95%E8%8E%B7.PNG)
这道题是典型的动态规划算法 

我们先判断最后一个楼梯
最后一个楼梯有两种上的办法 走一步或者走两步
分析可得动态转移方程为 dp[i] = dp[i-1]+dp[i-2]

初始条件
        //初始化
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

然后从左向右进行计算

### 代码

```cpp

class Solution {
public:
    int climbStairs(int n) {
        //判断大小
        vector<int> dp(n + 1);

        //如果过小 扩容
        if (dp.size() < 3)
            dp.resize(3);
        //初始化
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (auto i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
```