### 解题思路
调用reduce

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        from functools import reduce
        return reduce(lambda x, y:(x+m)%y, range(n+1))

```