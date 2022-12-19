### 解题思路
贪心算法，每次用最小物资满足最小的需求。
步骤：
1. 重排物资与需求
2. 从小到大比对物资&需求
3. 需求满足，两者++一位，需求不满足，物资++一位

### 代码

```python
class Solution(object):
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        i,j = 0,0
        while i < len(g) and j < len(s):
            if g[i] <= s[j]:
                i += 1
                j += 1
            else:
                j += 1
        return i
```