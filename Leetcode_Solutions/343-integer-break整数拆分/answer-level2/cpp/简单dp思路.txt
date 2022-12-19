### 解题思路
![13.jpg.png](https://pic.leetcode-cn.com/a65a05b838ecace92278d8da39f6c817f18dd8fc9aabb3edc21ef2cd81bc19f0-13.jpg.png)

任一数（大于1）均可至少写为一组两个数相加。如6=2+3，6=1+5。
此时设置dp数组，dp[i]表示数字i的各种组合中最大乘积。
+ 对于任意数字i. 利用一个for循环，从变量j=1，到j=i/2.
+ 将任意i分为两部分 j,i-j。两者相加为i 分别比较x1 = max(dp[i-j],j); x2=max(dp[j],j)的大小
+ x1*x2即此种情况的最大乘积

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if(n==0||n==1)
            return 0;
        vector<int>dp(n+1);
        dp[0] = 1,dp[1] = 1;
        for(int i=2;i<n+1;i++)
        {
            int rs = 1;
            for(int j=1;j<=i/2;j++) //分成两部分的和
            {
                int x1 = max(dp[i-j],i-j);
                int x2 = max(dp[j],j);
                if(rs<x1*x2)
                    rs = x1*x2;
            }
            dp[i] = rs;
        }
        return dp[n];
    }
};
```