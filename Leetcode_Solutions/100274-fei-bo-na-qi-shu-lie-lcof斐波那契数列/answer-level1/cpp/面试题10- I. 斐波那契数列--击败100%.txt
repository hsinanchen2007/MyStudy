### 解题思路
不要写1e9+7
每步取模
带缓存动态规划
![image.png](https://pic.leetcode-cn.com/0fa4ef8ad326fd64231b339815dcc284c60071087f0462cd48e65959166f750e-image.png)

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<long> dp(n+1);
        dp[0]=0,dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;  
        return dp[n];
    }
};
```