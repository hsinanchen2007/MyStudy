### 解题思路
from function import lru_cache

 @lru_cache(10 ** 8)
用来修饰类方法，可以为这个方法设置缓存，对递归的题目比较有用

### 代码

```python3
from functools import lru_cache

class Solution:
    @lru_cache(10 ** 8)
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        return self.climbStairs(n - 1) + self.climbStairs(n - 2)
    #原本的递归算法会时间超限
    #所以设置了缓存，这样子可以降低时间复杂度
```