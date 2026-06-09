献上我的代码，动态规划做的，会的人自然能看懂
```
int min(int a,int b)
    {
        return a<b?a:b;
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int s1=grid.size();
        int s2=grid[0].size();
        int dp[s1][s2];
        int sum=0;
        for(int i=0;i<s1;i++)
        {
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        sum=0;
        for(int i=0;i<s2;i++)
        {
            sum+=grid[0][i];
            dp[0][i]=sum;
        }
        if(s1==1)
        {
            return dp[0][s2-1];
        }
        if(s2==1)
        {
            return dp[s1-1][0];
        }
        for(int i=1;i<s1;i++)
        {
            for(int j=1;j<s2;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[s1-1][s2-1];
    }
```
