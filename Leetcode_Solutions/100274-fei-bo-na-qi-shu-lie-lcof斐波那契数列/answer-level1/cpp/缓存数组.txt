

### 代码

```cpp
class Solution {
public:
    int dp[101];
    int fib(int n) {
        if(dp[n]>0) return dp[n];
        if(n==0) {
            dp[n]=0;
        }
        else if(n==1||n==2) {
            dp[n]=1;
        }
        else{
            dp[n]=(fib(n-1)+fib(n-2))%1000000007;
        }
        return dp[n]%1000000007;
    }
};
```