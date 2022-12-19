### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1.0
        if n < 0:
            i = -n
        else:
            i = n
        while i != 0:
            if i % 2 != 0:
                res = res * x
            x = x * x
            i = i // 2
        if n < 0:
            res = 1 / res
        return res

```