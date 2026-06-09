这个算是dp经典题目了，没做过的的确很难想。但是看了答案你就会我擦！！

思路：设dp[i][j]为将word1[0~i-1] 编辑为 word2[0~j-1] 的最小距离。这里留意一下，i和j是表示的是word1、word2里面的字符个数，所以是可以从0开始到字符长度的。
1、当word1[i] == word2[j]的时候，那么dp[i][j] 就是 dp[i-1][j-1]，因为最后的i、j处的字符是相同的。也就是dp[i][j] = dp[i-1][j-1]
2、假设将word1[0~i-1]变为word2[0~j]需要的最小编辑距离是k，那么我们再将word1[i]删去，那么就完成了最后的编辑，总共需要k+1步。也就是dp[i][j] = dp[i-1][j] + 1
3、假设将word1[0~i]变为word2[0~j-1]需要的最小编辑距离是k，那么我们再将word2[j]删去，那么就完成了最后的编辑，总共需要k+1步。也就是dp[i][j] = dp[i][j-1] + 1
4、假设将word1[0~i-1]变为word2[0~j-1]需要的最小编辑距离是k，当word1[i] == word2[j]的时候，dp[i][j]=dp[i-1][j-1]；否则将word1或者word2最后一个字符再做一步修改，所以dp[i][j] = dp[i-1][j-1] + 1

综上所述，dp[i][j]就是从上面的几种类型里面选择最小的。
然后确定一下初始条件，dp[0][j]、dp[i][0]，这些没有办法，只能将字符一个个填上，所以是dp[i][0]=i,dp[0][j]=j

```
class Solution {
public:
    int minDistance(string word1, string word2) {
        long length1 = word1.size();
        long length2 = word2.size();
        vector<vector<int>> dp(length1+1, vector<int>(length2+1, 0));
        for (int i=1; i<=length1; i++) {
            dp[i][0] = i;
        }
        for (int i=1; i<=length2; i++) {
            dp[0][i] = i;
        }
        for (int i=1; i<=length1; i++) {
            for (int j=1; j<=length2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[length1][length2];
    }
};
```