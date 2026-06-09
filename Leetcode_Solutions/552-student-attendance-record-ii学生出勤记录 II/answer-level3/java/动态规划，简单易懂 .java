参考 ：https://blog.csdn.net/start_lie/article/details/84448182
```
class Solution {
    public int checkRecord(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 3;
        if(n==2)
            return 8;
        int max=1000000007;
        long [][][] dp = new long[n+1][2][3];
        //有两个数，且A个数为零，结尾不为L  --PP LP 
        dp[2][0][0]=2;
        //有两个数，且A的个数为1，结果不为L  AP 和PA LA
        dp[2][1][0]=3;
        //有两个数，没有A，且结尾为L  --PL
        dp[2][0][1]=1;
        //有两个数，一个A，且结尾为L -- AL
        dp[2][1][1]=1;
        //有两个数，结尾为两个L   ---LL
        dp[2][0][2]=1;
        //有两个数，结尾两个L，有一个A ---无
        dp[2][1][2]=0;
        for(int i=3;i<=n;i++){
            dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][0][2]+dp[i-1][0][1])%max;
            dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][1][0])%max;
            dp[i][0][1]=dp[i-1][0][0]%max;
            dp[i][1][1]=dp[i-1][1][0]%max;
            dp[i][0][2]=dp[i-1][0][1]%max;
            dp[i][1][2]=dp[i-1][1][1]%max;
        }
        return (int)((dp[n][0][0]+dp[n][1][0]+dp[n][0][1]+dp[n][1][1]+dp[n][0][2]+ dp[n][1][2])%max);
    }
}
```
