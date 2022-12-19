### 解题思路
同习题 [主站 343 题-343. 整数拆分](https://leetcode-cn.com/problems/integer-break/)

### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n ==2:
            return 1
        if n==3:
            return 2
        if n==4:
            return 4
        res = 1
        while n>4:
            res *= 3
            n -= 3
        res *= n
        return res
```