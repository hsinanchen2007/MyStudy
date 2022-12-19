没调用函数，写在if else 里了；还讨论了一下买卖次数为0的特殊情况，可能比较拙略。
```
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k<1||prices.size()<2)
            return 0;
        if (k>prices.size()/2)
        {
            int dp_i_0=0,dp_i_1=INT_MIN;
            for(int i=0;i<prices.size();i++)
            {
                int temp=dp_i_0;
                dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
                dp_i_1=max(dp_i_1,temp-prices[i]);
            }
            return dp_i_0;
        }
        else
        {
            int n=prices.size();
            int dp[n][k+1][2];
            for(int i=0;i<prices.size();i++)
            {
                for(int j=k;j>=1;j--)
                {
                     
                    if(i==0)
                    {
                    dp[i][j][0]=max(0,INT_MIN+prices[i]);
                    dp[i][j][1]=max(INT_MIN,-prices[i]);
                    }
                    else
                    {
                        dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                        if(j==1)
                            dp[i][j][1]=max(dp[i-1][j][1],-prices[i]);
                        else
                            dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
                    }
                }
            }
            return dp[n-1][k][0];
        }
    }
};
```
