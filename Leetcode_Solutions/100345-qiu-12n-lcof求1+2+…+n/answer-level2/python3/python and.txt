长知识了。。。。 
```python
class Solution:
    def sumNums(self, n: int) -> int:
        ret = 0
        def helper(n:int):
            nonlocal ret
            ret += n
            n > 0 and helper(n - 1)
        helper(n)
        return ret

```