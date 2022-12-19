### 解题思路
这题是第70题爬楼梯的进阶版，[爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)。也是采用动态规划的方法，将上一步的结果保存在数组中，进行判断。不同的是，这题新增了一个cost变量。

爬楼梯那题的动态规划方程为：f(n) = f(n-1)+f(n-2); 
这一题的我们设定f(n)为第一步需要从索引为0的楼梯开始爬，也就是第一步一定是一步。最后返回结果的时候，返回min(f(n), f(n-1))即可。
按照上述描述，该题的动态规划方程为：f(n) = min(cost(n) + f(n-1), cost(n) + f(n-2)),也就是第二步是爬一步还是两步的问题。

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(len == 0 || len == 1) return 0;

        int res;
        int dp[len];
        dp[0] = cost[len-1];
        dp[1] = cost[len-2];

        for(int i = 2; i < len; i++)
        {
            dp[i] = min(cost[len-i-1] + dp[i-1], cost[len-i-1] + dp[i-2]);
        }

        return min(dp[len-1], dp[len-2]);
    }
};
```