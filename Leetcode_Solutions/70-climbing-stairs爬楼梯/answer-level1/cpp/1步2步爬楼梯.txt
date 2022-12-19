### 解题思路
状态方程：f(n)=f(n-1)+f(n-2) 
            f(n-1)表示最后一迈为2阶台阶的所有可能情况
            f(n-2)表示最后一迈为1阶台阶的所有情况
         f(1)=1, f(2)=2 初始状态

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
```