### 解题思路
将数组排序。一道菜是否要做，取决于制作此菜的收益。收益包括两部分：一部分为此菜的满意度，另一部分为之后所做菜的满意度增值。如果收益为正，那么需要制作这道菜。还有一点可以确定，经过排序后，如果此道菜需要制作，那么之后的所有菜都需要。

### 代码

```python
class Solution:
    def maxSatisfaction(self, sat: List[int]) -> int:
        sat.sort()
        def total(sat):
            if not sat: return 0
            return sum([sat[i]*(i+1) for i in range(len(sat))])
        for i in range(len(sat)):
            if sum(sat[i:]) >= 0:
                return total(sat[i:])
        return 0
```