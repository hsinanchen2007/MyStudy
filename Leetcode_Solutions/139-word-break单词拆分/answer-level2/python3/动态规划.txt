在计算每个字符的dp[i]状态时，都循环遍历一遍wordDict字典，s[i]的值和和连个状态有关：
1、s[i]及其前n个字符是否能够组成wordDict中的word[k]
2、dp[i-len(word[k])]的状态是否为True

初始化dp表为False


```python []
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        s_len = len(s)
        if s_len < 1:
            return False

        dp = [False for i in range(s_len)]
        for end_index in range(s_len):
            for word in wordDict:
                start_index = end_index + 1 - len(word)
                if start_index < 0:
                    continue

                if s[start_index:end_index + 1] != word:
                    continue

                if start_index == 0 or dp[start_index - 1]:
                    dp[end_index] = True
                    break

        return dp[s_len - 1]
```

