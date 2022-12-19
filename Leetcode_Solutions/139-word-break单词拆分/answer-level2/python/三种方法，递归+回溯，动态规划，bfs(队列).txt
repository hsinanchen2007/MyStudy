

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict = dict(zip(wordDict, range(len(wordDict))))
        
        # 递归+回溯
        memo = [None for _ in range(len(s))]
        return self.dfs(s, wordDict, 0, memo)


        # dp[i]表示以i位置结尾的字符串是否符合条件
        dp = [False for _ in range(len(s)+1)]
        dp[0] = True
        for i in range(1, len(s)):
            for j in range(i):
                if dp[d]==True and s[j:i] in wordDict:
                    dp[i] = True
                    break
        return dp[-1]
    
        #队列
        from collections import deque
        queue = deque([0])
        memo = [False for _ in range(len(s))]
        while queue:
            start = queue.popleft()
            if memo[start]==False:
                for end in range(start+1, len(s)+1):
                    if s[start:end] in wordDict:
                        queue.append(end)
                        if end == len(s):
                            return True
                memo[start] = True
        return False

    def dfs(self, s, wordDict, start, memo):
        if start==len(s):
            return True
        if memo[start] is not None:
            return memo[start]
        for i in range(start+1, len(s)+1):
            if s[start:i] in wordDict and self.dfs(s, wordDict, i, memo):
                memo[start] = True
                return True
        memo[start] = False
        return False
```
