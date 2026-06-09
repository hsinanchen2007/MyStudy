dp数组i索引存放操作数为i时，可以得到A的最大数量

```
class Solution {
    public int maxA(int N) {
        if(N<=0)
            return 0;
        if(N<=6)
            return N;
        int[] dp=new int[N+1];
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=N;i++){
            dp[i]=dp[i-1]+1;//第i步按A
            for(int j=4;j<=i;j++){//j<=i
                dp[i]=Math.max(dp[i],dp[j-2]*(i-j+1));
            }//dp[j-2]*(i-j+1)是第j-2步按ctrl-A，j-1按了ctrl-C,j按了ctrl-V
        }
        return dp[N];
    }
}
```
