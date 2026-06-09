```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        '''
        思路：利用动态数规划的思想。设计一个dp数组，
              dp[i][j]表示word1的前i个词转化为word2前j个词所需的最小步数。
              那么：
              （1）当word1[i] == word2[j]时，我们只要考察word1的前i-1个词转化为
              word2的前j-1个词的最小步骤即可。
              （2）当word1[i]!=word2[j]时：
                  1）替换操作：我们将word1[i] 替换为 Word2[j],然后问题就等价于（1）
                  2）插入操作：我们先考察word1前i个词转化为word2前j-1个词所需的最小
                     步骤，然后在转为好的j-1个词的基础上，插入一个词，就能够成功转
                     化为前j个词。
                  3）删除操作：删除一个word1[i],考察word1前i-1个词转化为word2前j个词
                     所需的最小步骤。
                  so：
                  dp[i][j] = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1
        '''
        dp = [[0 for j in range(len(word2)+1)] for i in range(len(word1)+1)]
        # 初始化dp数组，我们的dp数组考虑了空串！
        for i in range(len(word2)+1):
            dp[0][i] = i
        for i in range(len(word1)+1):
            dp[i][0] = i
        for i in range(1,len(word1)+1):
            for j in range(1,len(word2)+1):
                # 因为有空串，所以这是word1[i-1] 和 word2[j-1]比较。
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1
                    
        return dp[-1][-1]
```
