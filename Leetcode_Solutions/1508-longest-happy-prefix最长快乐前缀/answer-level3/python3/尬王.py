### 解题思路
qswl  为什么比赛的时候用python提交超时。。。，python3又可以？？？

### 代码

```python3
class Solution:
    def longestPrefix(self, s: str) -> str:
        l = len(s)
        res = ""
        for i in range(l):
            if s[:i+1]==s[l-i-1:] and i!=l-1:
                res = s[:i+1]
        return res
```