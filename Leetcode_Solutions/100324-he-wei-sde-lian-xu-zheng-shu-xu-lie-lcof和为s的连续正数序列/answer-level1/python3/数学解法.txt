### 解题思路

我们相当于要求方程 f(lo, d) == target (序列[lo,d-1]求和) 的所有整数解，对于给定的 target，lo 与 d 之间有严格的约束，其中 d -> lo 的关系形式相对简单。

d 要保证对应的 lo >= 1 且是整数，即 `(d - d**2 + 2*target) / (2*d) >= 1`，解出 `d <= int(-.5 + .5*(1 + 8*target)**.5)`。

注意答案要求的结果的顺序。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        # print(int(-.5 + .5*(1 + 8*target)**.5) + 1)
        for d in reversed(range(2, int(-.5 + .5*(1 + 8*target)**.5) + 1)):
            # print(d)
            lo = (d - d**2 + 2*target) / (2*d)
            # print(lo)
            if lo.is_integer():
                lo = int(lo)
                ans.append(list(range(lo, lo + d)))
        return ans

```