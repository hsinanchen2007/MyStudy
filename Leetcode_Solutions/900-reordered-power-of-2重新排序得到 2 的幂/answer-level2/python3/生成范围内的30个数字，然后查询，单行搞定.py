总共也就三十个数，查询一下就完事了
```python
class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        return ''.join(sorted(str(N))) in {''.join(sorted(str(2 ** i))) for i in range(30)}

```

当然也可以把后面的集合变成数组，然后把join都去掉
