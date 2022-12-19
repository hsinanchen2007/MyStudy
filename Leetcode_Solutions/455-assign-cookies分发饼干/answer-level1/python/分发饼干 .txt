### 解题思路
排序，从胃口最小的小孩开始分发，尽可能使得小对小，大对大

### 代码

```python
class Solution(object):
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        count = 0
        i,j = 0,0
        while i < len(s) and j < len(g):
            if s[i] >= g[j]:
                count += 1
                i += 1
                j += 1
            else:i += 1
        return count
```