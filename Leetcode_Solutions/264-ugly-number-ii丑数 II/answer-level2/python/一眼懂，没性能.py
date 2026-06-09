### 解题思路
初初初初学者不会优化

### 代码

```python
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        b = [1]
        m = set()
        r = 0
        for _ in range(n-1):
            if len(m) == 0:
                for i in [2, 3, 5]:
                    o = i * b[-1]
                    m.add(o)
                r = min(m)
                b.append(r)
                m.remove(r)
            else:
                for i in [2, 3, 5]:
                    o = i * r
                    m.add(o)
                r = min(m)
                b.append(r)
                m.remove(r)

        return b[-1]
```