class Solution {
public:
    int knightDialer(int N) {
        const int a=N;
        int maxnum=1e9+7;
        int sum=0;
        int dp[10][a];
       if(N==1)
           return 10;
        for(int i=0;i<10;i++)
        {
            dp[i][0]=1;
        }
        int i=0;
        for(int s=1;s<a;s++)
        {
             dp[1][s]=(dp[8][s-1]+dp[6][s-1])%maxnum;
             dp[2][s]=(dp[7][s-1]+dp[9][s-1])%maxnum;
             dp[3][s]=(dp[4][s-1]+dp[8][s-1])%maxnum;
             dp[4][s]=(dp[0][s-1]+(dp[9][s-1]+dp[3][s-1])%maxnum)%maxnum;
             dp[6][s]=(dp[7][s-1]+(dp[1][s-1]+dp[0][s-1])%maxnum)%maxnum;
             dp[7][s]=(dp[2][s-1]+dp[6][s-1])%maxnum;
             dp[8][s]=(dp[1][s-1]+dp[3][s-1])%maxnum;
             dp[9][s]=(dp[4][s-1]+dp[2][s-1])%maxnum;
             dp[0][s]=(dp[4][s-1]+dp[6][s-1])%maxnum;
        }
        dp[5][a-1]=0;
        for(int k=0;k<10;k++)
        {
            sum=(sum+dp[k][a-1])%maxnum;
        }
        return sum;
    }
};