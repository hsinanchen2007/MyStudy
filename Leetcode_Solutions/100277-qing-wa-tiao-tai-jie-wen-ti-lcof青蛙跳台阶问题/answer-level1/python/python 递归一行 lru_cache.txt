### 解题思路

从第三级开始，每一级能到的途径有两种：
1. 从前一个台阶跳一步上来
2. 从前一个的前一个跳两步上来

那么它的结果就是前一步的结果加上前一步的前一步的结果。


lru_cache 装饰器当函数被调用过后会换存函数的返回值，下一次如果命中缓存，不再调用函数执行计算而是直接返回缓存的值

### 代码

```python
import functools
class Solution:
    @functools.lru_cache
    def numWays(self, n: int) -> int:
        return [1,1,2][n] if n < 3 else (self.numWays(n-1) + self.numWays(n-2)) % 1000000007
```