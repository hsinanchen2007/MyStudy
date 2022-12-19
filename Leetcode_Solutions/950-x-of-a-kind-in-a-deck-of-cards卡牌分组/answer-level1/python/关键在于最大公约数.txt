### 解题思路
如果能想到最大公约数，那么这道题就迎刃而解了。
统计各个数字出现的次数，求出这些次数的最大公约数，若为1，则不能分组。

### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        if len(deck) < 2:
            return False
        d = {}
        for de in deck:
            if de in d:
                d[de] += 1
            else:
                d[de] = 1
        keys = d.keys()
        if len(keys) == 1:
            if d[keys[0]]==1:
                return False
            return True
        #最大公约数的算法
        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)

        m = gcd(d[keys[0]], d[keys[1]])
        if m == 1:
            return False
        for k in keys[2:]:
            m = gcd(m, d[k])
        if m == 1:
            return False
        return True
```
执行用时32 ms, 在所有 Python 提交中击败了92.50%的用户