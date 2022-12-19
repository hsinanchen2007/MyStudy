### 解题思路

lru_cache 装饰器当函数被调用过后会换存函数的返回值，下一次如果命中缓存，不再调用函数执行计算而是直接返回缓存的值

### 代码

```python
import functools

class Solution:
    @functools.lru_cache
    def fib(self, n: int) -> int:
        return n if n < 2 else (self.fib(n-1) + self.fib(n-2))%1000000007
```