### 解题思路
双背包dp，填三维dp表

### 代码

```cpp
class Solution {
public:
    int max(int a,int b)
    {
        return a<b ? b : a;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> czero(strs.size(),0);
        vector<int> cone(strs.size(),0);
        for(int i=0;i<strs.size();i++)
        {
            string cur=strs[i];
            for(int j=0;j<cur.size();j++)
            {
             if(cur[j]=='0')   
                ++czero[i]; 
             if(cur[j]=='1')
                ++cone[i]; 
            }
        }
        vector<vector<vector<int> > > dp(m+1,vector<vector<int> >(n+1,vector<int>(strs.size())));
        for(int i=0;i<=m;i++)
        {
          for(int j=0;j<=n;j++)
          {
            if(i>=czero[0]&&j>=cone[0])
               dp[i][j][0]=1;
            else
               dp[i][j][0]=0;
          }
        }
        for(int i=0;i<=m;i++)
        {
          for(int j=0;j<=n;j++)
          {
             for(int k=1;k<strs.size();k++)
             {
                 dp[i][j][k]=dp[i][j][k-1];
                 if(i-czero[k]>=0&&j-cone[k]>=0)
                    dp[i][j][k]=max(dp[i][j][k],dp[i-czero[k]][j-cone[k]][k-1]+1);
             }
          }
        }   
        return dp[m][n][strs.size()-1];
    }
};
```