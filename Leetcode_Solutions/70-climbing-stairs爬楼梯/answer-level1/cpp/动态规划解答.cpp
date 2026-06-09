### 解题思路


初看觉得使用斐波那契递归应该就够了，但递归的劣势就在于处理计算了过多相同的子问题，所以最终超过运行时间限制，而动态规划相对就要高效很多。

![image.png](https://pic.leetcode-cn.com/3b0f72609def5ce6fcdef5028226474d74b38454768656617c2d8d45e20caae9-image.png)



最优子结构其实很简单：

dp[i] = dp[i-1] + dp[i-2]

融会贯通就可以。


### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        // 这难道不是斐波那契数列吗  青蛙爬楼梯吗 
        if(n == 1) return 1;
        if(n == 2) return 2;

        vector<int> dp(n, 0);

        dp[0] = 1;
        dp[1] = 2;

        for(int i = 2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n - 1];
    }
};
```