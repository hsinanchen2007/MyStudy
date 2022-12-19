```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        from collections import Counter
        wordDict = dict(Counter(wordDict))
        # 保存递归状态  节省时间
        map = {}
        
        def dfs(index):
            res = []
            # 递归的最底层  随便返回一个值  用于标记
            if index == len(s):
                return ' '
            # 如果当前状态的递归事先已经完成  就直接读回
            if index in map.keys():
                return map[index]
            for i in range(index, len(s)):
                if s[index:i+1] in wordDict.keys():
                    t = dfs(i+1)
                    if t == ' ':
                        res.append(s[index:i+1])
                    else:
                        for item in t:
                            res.append(' '.join([s[index:i+1], item]))
            map[index] = res
            return res
        
        res = dfs(0)
        return res
```