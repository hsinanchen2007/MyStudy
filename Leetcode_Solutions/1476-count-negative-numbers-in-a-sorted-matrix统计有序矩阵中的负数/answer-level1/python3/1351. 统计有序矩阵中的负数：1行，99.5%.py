![image.png](https://pic.leetcode-cn.com/6877dca527fc7372f66c65a475f995ff6ae8c1405d8f389b9b778732db68639e-image.png)


10秒做完的签到题，暴力法也可以99%。

```python []
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum(i < 0 for g in grid for i in g)
```

二分也行，涉及到反转，比暴力法慢点，最快36ms。

```python []
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum(bisect.bisect_left(g[:: -1], 0) for g in grid)
```
