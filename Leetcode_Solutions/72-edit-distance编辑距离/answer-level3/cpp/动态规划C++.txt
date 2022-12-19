### 解题思路
感谢官方题解带来的思路，对于其中的动态规划公式我一开始不能理解，后来去搜索了编辑距离问题的算法，手动画表求解了一遍，明白了。

动态规划公式：
if i == 0 且 j == 0，edit(i, j) = 0
if i == 0 且 j > 0，edit(i, j) = j (初始化）
if i > 0 且j == 0，edit(i, j) = i (初始化）
if i ≥ 1  且 j ≥ 1 ，edit(i, j) == min{ edit(i-1, j) + 1, edit(i, j-1) + 1, edit(i-1, j-1) + f(i, j) }，当第一个字符串的第i个字符不等于第二个字符串的第j个字符时，f(i, j) = 1；否则，f(i, j) = 0。

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int flag=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        //初始化第一列和第一行
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int j=0;j<=n;j++) dp[0][j]=j;
        //公式求解
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) flag=0;
                else flag=1;
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+flag);//注意min(,)函数只能求解两个数的最小值
            }
        }
        return dp[m][n];
    }
};
```