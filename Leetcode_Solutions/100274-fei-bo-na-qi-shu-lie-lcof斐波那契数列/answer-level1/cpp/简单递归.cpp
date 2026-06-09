这题其实没什么好说的，最简单的动态规划
dp[i]=dp[i-1]+dp[i-2]
因为只与前面两个值有关，可以优化空间复杂度到1
```
class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        int a=0,b=1;
        for(int i=2;i<=n;i++){
            int c = (a+b)%1000000007;
            a=b;
            b=c;
        }
        return b;
    }
};
```