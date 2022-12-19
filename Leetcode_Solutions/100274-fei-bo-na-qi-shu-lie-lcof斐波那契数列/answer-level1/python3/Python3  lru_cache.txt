### 解题思路
    #看了@comiee的评论去查了下装饰器@lru_cache的用法，做个备注
    #@lru_cache
    #一个为函数提供缓存功能的装饰器，缓存 maxsize 组传入参数，在下次以相同参数调用时直接返回上一次的结果,避免传入       相同的参数时重复计算。用以节约高开销或I/O函数的调用时间。
    #maxsize 设置为 None ，LRU(least recently used即最近最少使用原则)功能将被禁用且缓存数量无上限


### 代码    

```python3
class Solution:
    import functools
    @functools.lru_cache(None)
    def fib(self, n: int) -> int:
        if n<2:
            return n
        return (self.fib(n-1)+self.fib(n-2)) %1000000007

```