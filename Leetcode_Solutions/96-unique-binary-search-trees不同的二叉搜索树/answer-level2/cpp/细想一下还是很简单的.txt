## 动态规划
```C++ []
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        return dp[n];
    }
};

```
这一题动态规划的方法，仔细想一下还是很简单的。对于每一个根i他都是由左边子树（1, 2, ..., i - 1)和右边子树（i + 1, i + 2, ..., n)组成的。因此他的个数肯定是两个子树情况的积。而且，这种根一共有n个，再将这些加起来就可以了。

## 公式法

因为是明安图数直接可以使用公式

$$C_0 = 1, \qquad C_{n+1} = \frac{2(2n+1)}{n+2}C_n \qquad \qquad $$
```C++ []
class Solution {
public:
    int numTrees(int n) {
        long c = 1;
        for(int i = 0; i < n; i++)
            c = c * 2 * (2 * i  + 1) /(i + 2);
        return c;
    }
};

```