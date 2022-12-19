这一题和上一题难道不是一个题目吗。。
动态规划dp[i] = dp[i-1]+dp[i-2]
只有初始值不一样。
```
class Solution {
public:
    int numWays(int n) {
         if(n==0)
            return 1;
        int a=1,b=1;
        for(int i=2;i<=n;i++){
            int c = (a+b)%1000000007;
            a=b;
            b=c;
        }
        return b;       
    }
};
```