### 解题思路
二维数组动态规划，一个求了边界，用dp[m-1][n-1] 返回

二是不求边界，直接dp[m][n]返回

### 代码1： 求边界

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int rows = text1.size();
        const int cols = text2.size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // 求解边界 BEGIN
        if (text1[0] == text2[0])
            dp[0][0] = 1;
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0];
            if (text1[i] == text2[0]) {
                dp[i][0] = 1;
            }
        }
        for (int j = 1; j < cols; j++) {
            dp[0][j] = dp[0][j - 1];
            if (text1[0] == text2[j]) {
                dp[0][j] = 1;
            }
        }
        // 求解边界 END

        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++) {
                if (text1[i] == text2[j]) { // 遇到匹配字符
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else { // 不匹配时，继承左上中的较大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        return dp[rows - 1][cols - 1];
    }
};
```

### 代码2：直接
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        if(m==0||n==0) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
   
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
```
