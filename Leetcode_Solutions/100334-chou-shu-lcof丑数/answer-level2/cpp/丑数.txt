### 解题思路
参考别人的代码

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n,0);
        int p2=0,p3=0,p5=0;
        dp[0] = 1;
        for(int i = 1;i < n;i++){
            dp[i] = min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
            if(dp[i] == dp[p2]*2) p2++;             //注意这里不能用else if
            if(dp[i] == dp[p3]*3) p3++;             //会导致丑数重复
            if(dp[i] == dp[p5]*5) p5++;             //比如6，既可以从基数2得到，又可以从3得到，就会重复。。。
        }
        return dp[n-1];
    }
};
```