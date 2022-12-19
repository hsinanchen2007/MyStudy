### 解题思路
此处记录一下个人理解的各个题解中三种情况为什么如此改变。
不相同时分为三种情况：1，插入表达式为dp[i][j-1]，当需要插入时我们处于word1的第i个位置，而我们插入最简单的逻辑应该是i+1，但是因为动态规划是由底部向顶部靠拢所以我们的i+1中没有值所以不能单纯的由i+1，当对word1修改时其实也是对word2进行修改，word1增加就相当于word2减少，如ab和abd，ab加d得abd，abd减d等于ab，所以我们可以把i+1的情况改为j-1。
2，删除的表达式为dp[i-1][j]，当进行删除操作时就很好理解当前我们在i的位置需要减去一个，则为i-1；
3，修改的表达式为dp[i-1][j-1]，当进行修改的时候我们实际上可以看作当处于i-1和j-1的位置时同时添加一个相同的数。
最后就是在3中情况中不断取最小值直到顶部最后就是我们的最优解。此处灵感来源于[@Time-Limit](/u/time-limit/)
### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i < dp.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};


```