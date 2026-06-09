## 思路:

没啥好说的，贪心排序比较即可

## 代码:

```python
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        res = 0
        i = 0
        j = 0
        while i < len(g) and j < len(s):
            while j < len(s) and g[i] > s[j]:
                j += 1
            if j < len(s):
                res += 1
                i += 1
                j += 1
        return res
```

