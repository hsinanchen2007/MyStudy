### 解题思路
因为最多只能给孩子一个饼干，则将s和g从小到大排序，使每个拿到的都是当前最小就能满足他胃口大小的饼干即可

### 代码

```python
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        if g == None or s == None:
            return 0
        else:
            g = sorted(g)
            s = sorted(s)
        i = 0
        j = 0
        ret = 0
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                ret += 1
                i += 1
            j += 1
        return ret  
```