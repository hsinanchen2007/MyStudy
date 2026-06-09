### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        res = 0
        for i in range(2, n+1):
            res = (res + m) % i
        return res

```