字符串text1和text2，构造一个DP表（下表来自https://leetcode-cn.com/problems/longest-common-subsequence/solution/dong-tai-gui-hua-zhi-zui-chang-gong-gong-zi-xu-lie/）：
![image.png](https://pic.leetcode-cn.com/4ec0bb0900d502075bdfd12dccf4be42a5e63f2cce93a02c431ac92c61f19c8c-image.png)
```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        //if (m==0 || n==0) return 0;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0)); 
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) { // dp[i][j]代表text1前i个数与text2前j个数的最大公共子序列
                if(text1[i-1] == text2[j-1]) dp[i][j]=dp[i - 1][j - 1] + 1;//字符在公共子序列中
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);//来自text1、text2的两字符中至少有一个字符不在公共子序列中，需要丢弃一个，谁能让公共子序列最长，就留谁
            }
        }
        return dp[m][n];
    }
};
```
