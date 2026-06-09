找到wordDict中最长（maxLen）的字符串，每次只遍历当前位置之前maxLen范围内的字符。因为当前位置的状态只与前面maxLen范围内的字符相关，所以状态存储的数组也可以缩小到maxLen，这里不做讨论。

```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        maxlen = 0
        for word in wordDict:
            maxlen = max(maxlen, len(word))
        state = [False] * (n + 1)
        state[0] = True
        for i in range(1, n+1):
            tmp = max(0, i - maxlen)
            for j in range(tmp, i):  #遍历当前位置i之前maxLen范围内的元素
                if s[j:i] in wordDict and state[j]:
                    state[i] = True
                    break
        return state[-1]
```