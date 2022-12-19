这道题的题目描述很奇怪，不是统计单词的数量，而是统计连续的不是空格的字符的数量。
```
class Solution:
    def countSegments(self, s: str) -> int:
        s = s.strip()
        if s == '':
            return 0
        res = 0
        for i in s.split():
            if i == '':
                continue
            res += 1
        return res
```

