### 解题思路
    打卡学习 ~ ~ ~
### 代码

```cpp
//贪心
class Solution {
public:
    int integerBreak(int n) {
        //判特例
        if(n < 2) return 0;
        if(n == 2 || n == 3) return n - 1;
        if(n == 4) return 4;

        int res = 1;

        //划分尽可能多的3
        while(n >= 5) res *= 3,n -= 3;

        return res * n;
    }
};

//dp
class Solution{
public:
    int integerBreak(int n){
        vector<int> dp(n + 1,0);
        dp[0] = dp[1] = 0;
        dp[2] = 1;
        for(int i = 3;i <= n;i++)
            for(int j = 1;j < i;j++)
                dp[i] = max(dp[i],max(j,dp[j]) * max(i - j,dp[i - j]));
        return dp[n];
    }
};

```