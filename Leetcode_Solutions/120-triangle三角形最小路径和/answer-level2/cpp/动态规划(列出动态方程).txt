### 解题思路
动态方程为 dp[i][j] = min(dp[i-1][j] + triangle[i][j],dp[i-1][j-1] + triangle[i][j]) i为到达i层，j位置时的最小路径
思路1:
    1.上一层没有对应的j时，dp[i][j] = triangle[i][j] + dp[i-1][j-1]
    2.上一层没有对应的j-1时，j-1可能为-1，则dp[i][j] = triangle[i][j] + dp[i-1][j]
    3.否则就是通用的动态方程dp[i][j] = min(dp[i-1][j] ,dp[i-1][j-1] ) + triangle[i][j]



### 代码

```cpp
class Solution {
public:
    //回朔
    int minv = 0x7fffffff;
    void dfs(vector<vector<int>>& triangle,int cur,int lastindex,int sum)
    {
        if(cur == triangle.size())
        {
            minv = min(minv,sum);
            return;
        }
        dfs(triangle,cur+1,lastindex,sum + triangle[cur][lastindex]);
        dfs(triangle,cur+1,lastindex+1,sum + triangle[cur][lastindex+1]);
    }
    int minimumTotal2(vector<vector<int>>& triangle) {
        dfs(triangle,1,0,triangle[0][0]);
        return minv;
    }
    //dp[i][j] = min(dp[i-1][j] + triangle[i][j],dp[i-1][j-1] + triangle[i][j])
    int dp[300][300];
    int minimumTotal(vector<vector<int>>& triangle) {
        int minv = 0x7fffffff;
        dp[0][0] = triangle[0][0];
        for(int i=1;i<triangle.size();i++)
            dp[i][0] = dp[i-1][0] + triangle[i][0];
        for(int i=1;i<triangle.size();i++)
        {
            int len = triangle[i].size();
            for(int j=0;j<len;j++)
            {
                if(j == 0)
                   dp[i][j] =  dp[i-1][j] + triangle[i][j];
                else if(j == len-1)
                    dp[i][j] =  dp[i-1][j-1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
                //cout<<dp[i][j]<<endl;
            }
        }
        int len = triangle.size()-1;
        for(int i=0;i<triangle[len].size();i++)
        {
            minv = min(dp[len][i],minv);
        }
        return minv;
    }
};
```