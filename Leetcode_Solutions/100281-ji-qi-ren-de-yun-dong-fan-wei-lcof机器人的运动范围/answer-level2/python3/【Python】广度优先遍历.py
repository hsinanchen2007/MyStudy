## 解题思路

这道题应该是有深层规律的，但目前分析不出来。因此，只剩遍历这个简单有效的手段。

遍历上，其实也有剪枝的余地。根据机器人的运动规律，可达区域一定是横竖相连的。因此，广度优先遍历（BFS）会是一个较好的策略，能在没有下一层时，提前结束。

在判断坐标是否可达上，要求十进制每一位之和小于`k`。暂时归纳不出规律，只能硬来了。

## 代码

```python3
from functools import lru_cache


@lru_cache(maxsize=None)
def sum_num(num):
    sumation = 0
    while num:
        sumation += num % 10
        num //= 10
    return sumation


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        return sum(1 for _ in self.bfs(m, n, k))

    @staticmethod
    def bfs(m, n, k):
        layer = {(0, 0)}
        while layer:
            nexts = set()
            for i, j in layer:
                if Solution.good(i, j, k):
                    yield i, j
                    if i + 1 < m:
                        nexts.add((i + 1, j))
                    if j + 1 < n:
                        nexts.add((i, j + 1))
            layer = nexts

    @staticmethod
    def good(i, j, k):
        return (sum_num(i) + sum_num(j)) <= k
```

> 执行用时 : `48 ms`, 在所有 Python3 提交中击败了`95.38%`的用户
> 内存消耗 : `13.7 MB`, 在所有 Python3 提交中击败了`100.00%`的用户