### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int n=prices.size(),tag=2;
        if(k>n/2)   //k过大时，dp数组占用太多内存报错，其实只要k比天数的一半大，就相当于没有次数限制了
        {           //就变成Ⅱ类问题了，因为买卖一次至少花费两天
            int res=0;
            for(int i=0;i<prices.size()-1;i++)
            {
                if(prices[i]<prices[i+1])
                    res+=(prices[i+1]-prices[i]);
            }
        return res;    
        }
        int dp[n][k+1][tag];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k+1;j++)
            {
                for(int m=0;m<tag;m++)
                {
                    dp[i][j][m]=0;
                    //dp[i][0][1]=INT_MIN;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=k;j>=1;j--)
            {
                if(i-1==-1)
                {   
                    //dp[i-1][k][0]=0,dp[i-1][k][1]=INT_MIN;
                    dp[i][j][0]=0;//max(0,INT_MIN+prices[i]);
                    dp[i][j][1]=-prices[i];//max(INT_MIN,0-prices[i]);
            
                }
                else
                {
                    dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                    dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
                }
            }                                                           
        }
        return dp[n-1][k][0];
    }
};
```