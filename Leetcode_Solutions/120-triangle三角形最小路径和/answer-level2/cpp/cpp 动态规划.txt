//1.状态：高m和每一层的长度n   ；选择：下一行相邻节点
//2.dp[i][j]=x 表示到triangle[i][j]的最小路径和为x
//  base case: dp[0][0]=trangle[0][0] 
//           dp[i][0]=tran[0][0]+tran[1][0]+...+tran[i][0]
//           dp[i][i]=tran[0][0]+tran[1][1]+...+tran[i][i]
//3.转移方程：dp[i][j]=min(dp[i-1][j-1], dp[i-1][j])+tran[i][j]

```

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, triangle[0][0]));
        for(int i = 1; i < m; ++ i) {
            for(int k = 1; k <= i; ++ k) {
                dp[i][0] += triangle[k][0];
                dp[i][i] += triangle[k][k];
            }
        }
        for(int i = 1; i < m; ++ i) {
            //第i行的列数为i+1,这里要去除掉最右边一列
            for(int j = 1; j < i; ++ j) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        int result = dp[m - 1][0];
        for(auto k : dp[m - 1]) {
            result = min(result, k);
        }
        return result;
    }
};
```
