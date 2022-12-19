### 解题思路
通过set和map减小运行时间

### 代码

```python3
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        xx = [0, 1, 0, -1]
        yy = [1, 0, -1, 0]
        ob = set(map(tuple, obstacles))
        x = y = 0
        r = 0
        res = 0
        for c in commands:
            if c > 0:
                for _ in range(c):
                    if (x + xx[r], y + yy[r]) not in ob:
                        x = x + xx[r]
                        y = y + yy[r]
                    else:
                        break
            elif c == -1:
                r += 1
                r %= 4
            else:
                r += 3
                r %= 4
            res = max(res, x ** 2 + y ** 2)

        return res
```