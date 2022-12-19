这道题用回溯法超时。

不过可以用cache加速。

也是dfs，不过是加速后的dfs。
```
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        def helper(s,wordDict,memo):
            if s in memo:
                return memo[s]
            if not s:
                return []
            res = []
            for word in wordDict:
                if not s.startswith(word):
                    continue
                if len(s) == len(word):
                    res.append(word)
                else:
                    re = helper(s[len(word):],wordDict,memo)
                    for item in re:
                        item = word + ' ' + item
                        res.append(item)
            memo[s] = res
            return res
        return helper(s,wordDict,{})
```
