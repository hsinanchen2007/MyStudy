### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        """
        动态规划解题三步走：
        1. dp[i][j]表示word1的前i个字符变成word2的前j个字符需要的最小步骤
        2. 关系：if word1[i] == word2[j]: dp[i][j] = dp[i-1][j-1]
                else:
                    c1=word1[i] 与 c2=word2[j] 可以做三种变更：
                        改：c1变成c2: dp[i][j] = dp[i-1][j-1] + 1
                        删：删除c1，c2与word1[i+1]比较：dp[i][j] = dp[i][j-1] + 1
                        增：在c1前面一个位置增加一个c2字符，c1与word[j+1]比较：dp[i][j] = dp[i-1][j] + 1
                    三种变更取哪种，取决于那种方式是最小步骤：
                        dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
        3. 初始值：dp[0][0...n]与dp[0...m][0]都应该有初始值，因为他们是没法通过计算获取的。
                  dp[0][0] = 0 if word1[0]=word2[0] else 1
                  dp[0][1] = 1 if word1[0] in word2[:1] else 2
                  dp[0][2] = 2 if word1[0] in word2[:2] else 3
                  ...
                  dp[1][0] = 1 if word2[0] in word1[:1] else 2
                  dp[2][0] = 2 if word2[0] in word1[:2] else 3
                  ...
        :param word1:
        :param word2:
        :return:
        """
        if len(word1) == 0 or len(word2) == 0:
            return len(word2)+len(word1)
        # 初始值
        dp = [[]]
        c1 = word1[0]
        for j in range(len(word2)):
            dp[0].append(j if c1 in word2[:j+1] else j+1)
        c2 = word2[0]
        for i in range(1, len(word1)):
            dp.append([i if c2 in word1[:i+1] else i+1])
            
        def _dpfunc():
            for i in range(1, len(word1)):
                for j in range(1, len(word2)):
                    if word1[i] == word2[j]:
                        dp[i].append(dp[i-1][j-1])
                    else:
                        dp[i].append(min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1)
        _dpfunc()
        return dp[len(word1)-1][len(word2)-1]
```