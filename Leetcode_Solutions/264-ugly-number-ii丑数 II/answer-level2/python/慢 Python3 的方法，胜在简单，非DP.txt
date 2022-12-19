每次就找最小的还没用过的丑数分别乘上2、3、5，加入到栈中。
```
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        c = set()
        m = 1
        stack = [1]
        d = []
        while len(d) < n:
            m = min(stack)
            stack.remove(m)
            d.append(m)
            if m * 2 not in c:
                stack.append(m * 2)
                c.add(m * 2)
            if m * 3 not in c:
                stack.append(m * 3)
                c.add(m * 3)
            if m * 5 not in c:
                stack.append(m * 5)
                c.add(m * 5)
        return d[n - 1]
```