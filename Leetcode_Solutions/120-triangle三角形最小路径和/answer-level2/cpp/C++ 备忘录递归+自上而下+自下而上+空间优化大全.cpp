![截屏2020-03-31下午8.59.02.png](https://pic.leetcode-cn.com/d81b8d8e68414213821d50e2cbc247ee87bf7e5784fd289edcabc7141fd0df1b-%E6%88%AA%E5%B1%8F2020-03-31%E4%B8%8B%E5%8D%888.59.02.png)


```
class Solution {
public:
    //备忘录
    int minimumTotal1(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int> > dp(row, vector<int>(row, -1));
        return helper(triangle, 0, 0, dp);
    }

    int helper(vector<vector<int>>& triangle, int level, int index,vector<vector<int> >& dp)
    {
        if(level == triangle.size() - 1) {
            return triangle[level][index];
        }

        if(dp[level][index] != -1) {
            return dp[level][index];
        }
        int left = helper(triangle, level + 1, index, dp);
        int right = helper(triangle, level + 1, index + 1, dp);
        dp[level][index] = triangle[level][index] +  min(left, right);
        return dp[level][index];
    }
    //dp 从上到下
    int minimumTotal2(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int dp[row][row];
        dp[0][0] = triangle[0][0];
        for(int i = 1;i<row;i++){
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            dp[i][triangle[i].size() - 1] = triangle[i][triangle[i].size()-1] + dp[i-1][triangle[i].size()-2];
        }

        for(int i=1;i<row;i++)
        {
            for(int j = 1;j < triangle[i].size() - 1;j++)
            {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        int minv = dp[row - 1][0];
        for(int i = 1;i<row;i++)
        {
            minv = min(minv, dp[row - 1][i]);
        }
        return minv;
    }

     //dp 从上到下，空间优化
    int minimumTotal3(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int dp[row];
        dp[0] = triangle[0][0];

        for(int i=1;i<row;i++)
        {
            int erow = triangle[i].size();
            dp[erow - 1] =  dp[erow - 2] + triangle[i][erow - 1];
            for(int j = erow - 2;j>=1;j--)
            {
                dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
            dp[0] =  dp[0] + triangle[i][0];
        }
        int minv = dp[0];
        for(int i = 1;i<row;i++)
        {
            minv = min(minv, dp[i]);
        }
        return minv;
    }

    //dp 从下到上
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int dp[row];
        
        for(int i = 0;i<row;i++){
            dp[i] = triangle[row-1][i];
        }

        for(int i= row - 2;i >=0;i--)
        {
            for(int j = 0;j < triangle[i].size();j++)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};
```
