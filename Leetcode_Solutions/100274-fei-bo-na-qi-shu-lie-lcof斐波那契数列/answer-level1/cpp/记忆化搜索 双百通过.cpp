### 解题思路
取余运算规则 (a + b) % p = (a % p + b % p) % p 
由递归式可得：F(N) % 1e9+7 = (F(N-1)%1e9+7 + F(N-2)%1e9+7) % 1e9+7
数组中存储取余后的结果，最后直接返回dp[n]即可。

![1.png](https://pic.leetcode-cn.com/1d058c38e8a71ea59c08dd596baf2cf9bfbd73f5e3fc8d2997b5506db22f93e0-1.png)


### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        int dp[101];
        dp[0]=0; dp[1]=1;
        
        for(int i=2;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        
        return dp[n];
    }
};
```