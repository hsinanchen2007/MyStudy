
# 贪心算法

* 先将g和s排序
* 遍历s，依次发现大于g的数量

```python
class Solution:
    def findContentChildren(self, g, s) -> int:
        g.sort()
        s.sort()
        j = 0
        for i in range(len(s)):
            if j >= len(g):
                break
            if s[i] >= g[j]:
                j += 1
        return j
```