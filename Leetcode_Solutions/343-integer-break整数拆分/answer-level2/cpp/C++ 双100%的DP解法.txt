C++ 双100%的DP解法
```cpp
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        if(n<4) return n-1;
        dp[1]=0;dp[2]=1;dp[3]=2;dp[4]=4;
        for(int i=5;i<=n;++i){
            if(dp[i-1]%2==0) dp[i]=dp[i-1]/2*3;
            else dp[i]=dp[i-1]/3*4;
        }
        return dp[n];
    }
};
```
经过前期简单的归纳发现当n大于4时，乘积就会大于和，所以可以推断大于4的所有整数都必须分解为2和3的乘积。
所以在推状态转移式时只需要在dp[i-1]的基础上做一个选择而已：
                     
1、若dp[i-1]能被2整除，则说明其乘积最大值包含因子2，则将2用3替代即为dp[i];
                       
2、若dp[i-1]不能被2整除，则一定能被3整除，将3用4（即2*2）替代即为dp[i];

