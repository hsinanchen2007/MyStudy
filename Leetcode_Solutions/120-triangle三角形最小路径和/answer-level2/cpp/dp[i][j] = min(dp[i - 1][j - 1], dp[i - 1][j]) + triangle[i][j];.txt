### 解题思路
要注意因为是三角形，所以每一个位置可以取dp[i - 1][j]或者dp[i - 1][j - 1]，边界要特判。

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[200][200];
        dp[0][0] = triangle[0][0];
        if(n == 1)
        return dp[0][0];
        dp[1][0] = dp[0][0] + triangle[1][0];
        dp[1][1] = dp[0][0] + triangle[1][1];
        if(n == 2)
        return min(dp[1][0], dp[1][1]);
        for(int i = 2 ; i < n ; ++i)
        {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for(int j = 1 ; j < i; ++j)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        int min = dp[n - 1][0];
        for(int i = 1 ; i < n ; ++i)
        {
            if(dp[n - 1][i] < min)
                min = dp[n - 1][i];
        }
        return min;
    }
};
```