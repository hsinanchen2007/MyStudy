### 解题思路
对wordDict进行循环，使用dfs

### 代码

```python3
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        res = []
        memo = {}
        return dfs(s, memo, wordDict)
    
def dfs(s, memo, wordDict):
    if s in memo:
        return memo[s]
    if s == '':
        return []
    res = []
    for word in wordDict:
        if not s.startswith(word):
            continue
        # 循环到最后而且匹配，则append
        if len(word) == len(s):
            res.append(word)
        # 匹配但是没有循环到最后，于是继续往下，之后需要对返回的结果分别加上当前的word
        else:
            rest = dfs(s[len(word):], memo, wordDict)
            for item in rest:
                item = word + ' ' + item
                res.append(item)
    # 保存当前s的结果
    memo[s] = res
    return res
```