### 解题思路
这题做了很多遍，从[单词拆分](https://leetcode-cn.com/problems/word-break/) 过来的，自然想到的是DP，但是直接DP就超时了。
看了一下大家都用的是DFS。试了一下，dfs果然不超时。那问题来了，dp是dfs的一种优化，相比之下少了调用栈，时间只能更快不会更慢，为什么dfs不超时，dp反而超时。

看了一下超时的case
`"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]`

s中间有个b，导致最后结果比为空。因为dfs递归过来，可以发现这个“b”，所以没有浪费计算。但是dp从左到右，之前一直都有计算，直到“b”才发现有问题。所以在这个场景下dp有计算浪费。
那怎么避免，两次dp，第一次判断最后是不是有结果。如果最后真的有结果，那再递归求一下。


### DFS
```
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        def dfs(idx):
            if idx not in cache:
                result = []
                for i in xrange(idx + 1, len(s) + 1):
                    if s[idx:i] in word_set:
                        for sub in dfs(i):
                            if sub:
                                result.append(s[idx:i] + " " + sub)
                            else:
                                result.append(s[idx:i])
                cache[idx] = result
            return cache[idx]
        
        
        cache = {len(s): [""]}
        word_set = set(wordDict)
        return dfs(0)
```

### DP

```python3
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        words = set(wordDict)
        n = len(s)
        dp1 = [False] * (n + 1)
        dp1[0] = True
        for i in range(1, n + 1):
            for j in range(i - 1, -1, -1):
                if dp1[j] and s[j:i] in words:
                    dp1[i] = True
                    break

        dp = [[] for _ in range(n + 1)]
        if dp1[-1]:
            dp[0] = [""]
            for i in range(1, n + 1):
                for j in range(i - 1, -1, -1):
                    if s[j:i] in words:
                        for sub in dp[j]:
                            if sub:
                                dp[i].append(sub + " " + s[j:i])
                            else:
                                dp[i].append(s[j:i])
        return dp[-1]
        
```