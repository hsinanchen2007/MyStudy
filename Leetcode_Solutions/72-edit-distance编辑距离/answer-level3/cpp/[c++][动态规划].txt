### 解题思路
思路为将EDIT, ADD, 和DEL三种情况单独考虑。建立DP[i][j]，代表使用**i个word1** 去匹配 **j个word2** 的最小编辑次数。
为什么不直接用dp[i][j]其中i，j都表示下标而不是个数呢？因为如果使用下标，dp[0][0]代表word1的第一个字符去match word2的第一个字符的情况，而最开始的情况应该是使用word 1去match空字符，并且在本题中，取0个word1,和取0个word2这两个状态都是需要的，因此需要额外增加一行和一列。

这三个dp状态转移方程成立的原因，是因为当我们假设使用i个word1去match j个word2的情况时，*两个字符串的最后一个字符**一定相等***。因此我们可以这样想，要使得两个字符串最后一位相等并且之前的部分匹配，有多少种做法呢？

有三种情况：

EDIT: dp[i][j] = dp[i-1][j-1] + !(word2[j-1] == word1[i-1]), 假设要编辑使得word2[j-1]与word[i-1] 的最后一位相同，那么首先得确保word1和word2的最后一位之前的部分相同（需要dp[i-1][j-1]个操作），然后再确保最后一位match。如果最后一位已经match了，那就增加修改次数0，否则增加修改次数1.

ADD: dp[i][j] = dp[i][j-1] + 1, 代表用i个word1先match j-1个word2，然后最后一位添加word2最后一个字符使得两部分相等。

DEL: dp[i][j] = dp[i-1][j] + 1, 即i-1个字符已经能把j个字符match了，那么如果要使用删除来让他们match，就删掉最后一位即可。

因此使用dp来求解的核心思想是： **假设我在某个状态，采取了某个行动，在基于此行动已经执行的基础上更新结果**。

### 代码

```cpp
using namespace std;

class Solution{
    public:
        int minDistance(string word1, string word2){
            vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 999999));
            for(int i=0;i<=word1.length();i++) dp[i][0] = i;
            for(int i=0;i<=word2.length();i++) dp[0][i] = i;
            for(int i=1;i<=word1.length();i++){
                for(int j=1;j<=word2.length();j++){
                    // Edit, add, del
                    dp[i][j] = min(dp[i-1][j-1] + !(word2[j-1] == word1[i-1]),
                                    min(dp[i][j-1]+1, dp[i-1][j]+1));
                }
            }
            return dp[word1.length()][word2.length()];
        }
};

```