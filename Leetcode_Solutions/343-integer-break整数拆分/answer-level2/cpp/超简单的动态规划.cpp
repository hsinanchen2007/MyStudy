### 解题思路
这是一个规律，从5开始尽可能的将数划分为3这样乘积就会是最大的。

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
       if(n==2||n==3)
       {
           return n-1;
       }
       vector<int>dp(n+1);
       dp[2]=2;
       dp[3]=3;
       dp[4]=4;
       for(int i=5;i<=n;i++)
       {
           dp[i]=dp[i-3]*3;
       }
       return dp[n];
    }
};
```