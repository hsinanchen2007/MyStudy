### 解题思路
思路很简单，就是用当前行的数据和上一行的相比较然后选择小的相加即可

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
        {
            return 0;
        }
                  vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),0));
                  dp[0][0]=triangle[0][0];
                 for(int i=1;i<triangle.size();i++)
                 {
                     for(int j=0;j<=i;j++)
                     {
                         if(j==0)
                         {
                              dp[i][j]=triangle[i][j]+dp[i-1][j];
                         }
                         else if(j==i)
                         {
                           dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                         }
                         else
                         {
                              dp[i][j]=triangle[i][j]+(dp[i-1][j-1]<dp[i-1][j]?dp[i-1][j-1]:dp[i-1][j]);
                         }
                        if((i==triangle.size()-1)&&j>0)
                        {
                               if(dp[i][j]>dp[i][j-1])
                               {
                                   dp[i][j]=dp[i][j-1];
                               }
                        }
                        cout<<dp[i][j]<<" ";
                     }
                     cout<<endl;
                 }
              return dp[triangle.size()-1][triangle.size()-1];
    }
};
```