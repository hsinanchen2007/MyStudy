### 解题思路
使用字典来记录元素出现的次数，然后使用gcd来计算是否存在某个不为1的x。
为了效率，计算前过滤掉了如果某个元素唯一这种情况。

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        l = len(deck)

        if l < 2:
            return False

        d = {}
        for i in deck:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] = d[i] + 1

        m = min(d.values())
        if m < 2:
            return False
        import math
        k = math.gcd(l, m)
        if k == 1:
            return False
        tmp = k
        for v in d.values():
            tmp = math.gcd(v, tmp)
        if tmp < 2:
            return False
        return True
```