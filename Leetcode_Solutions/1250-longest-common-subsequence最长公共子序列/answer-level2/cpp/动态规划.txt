### 解题思路
对于给定字符串text1的位置i和字符串text2的位置j，定义f(i,j)表示text[:i-1]和text[:j-1]的最长公共子序列。如果此时text1[i-1] == text2[j-1]，那么
f(i,j)=f(i−1,j−1)+1
如果不相等，那么此时的最大值应该来自两部分：text[:i]和text[:j-1]、text[:i-1]和text[:j]。
f(i,j)=max(f(i,j−1),f(i−1,j))


### 代码

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        int lenA = text1.length();
        int lenB = text2.length();
        for(int i=0;i<=lenA;i++)
        {
            dp[i][0] = 0;
        }
        for(int j=0;j<=lenB;j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1;i <= lenA;i++)
        {
             for(int j = 1;j <= lenB;j++)
             {
                if(text2[j-1] == text1[i-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[lenA][lenB];
    }
};
```