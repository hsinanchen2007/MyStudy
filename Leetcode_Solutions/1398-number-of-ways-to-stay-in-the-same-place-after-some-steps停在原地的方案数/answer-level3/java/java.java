创建一个大小为arrlen的数组dp,显然arrlen过大时超出的长度无意义,所以限制长度.
dp[i]表示经过若干步后到达坐标i处的方案数.
初始dp[0]=1,表示刚开始位于0位置上.
dp通过走一步变成ndp,ndp[i]=dp[i-1]+dp[i]+dp[i+1],数组越界部分置为0.
经过steps步后得到dp[i]即为到坐标i处的方案数.

```
class Solution {
    public int numWays(int steps, int arrLen) {
        if(arrLen>steps/2+1){
            arrLen=steps/2+1;
        }
        long dp[] = new long[arrLen];
        long mod = 1000000007;
        dp[0]=1;
        for(int i=0;i<steps;i++){
            long ndp[] = new long[arrLen];
            for (int j=0;j<arrLen;j++){
                ndp[j]+=dp[j];
                if(j-1>=0){
                    ndp[j]+=dp[j-1];
                }
                if(j+1<arrLen){
                    ndp[j]+=dp[j+1];
                }
                ndp[j]%=mod;
            }
            dp=ndp;
        }
        return (int)dp[0];
    }
}
```
