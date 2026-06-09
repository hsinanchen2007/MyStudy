### 解题思路
这道题一看就是动态规划，递推式为dp[i] = dp[i - len(word)] and s[i - length + 1:i + 1]，我觉得理解并不是很难。
虽然这道题思路不难，但有两个细节需要注意：
（1）注意从min(word_len_dict)位置开始遍历，而不是max。
（2）当dp[i]计算出来是True时，就应该break。
以上两个细节都是我错过的地方，所以提醒一下。

### 代码

```python
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        if wordDict == []:
            return False
        dp = [False] * len(s)
        word_len_dict = [len(word) for word in wordDict]
        # 设置边界
        for word, length in zip(wordDict, word_len_dict):
            if length <= len(s) and word == s[:length]:
                dp[length - 1] = True
        print(dp)
        # 
        for i in range(min(word_len_dict), len(dp)): # 注意这里是min
            for word, length in zip(wordDict, word_len_dict):
                ind = i - length
                if ind < 0 or dp[i]:
                    continue
                res = dp[ind] and (word == s[ind + 1:i + 1])
                if res:
                    dp[i] = True
                    break
        print(dp)
        return dp[-1]
```