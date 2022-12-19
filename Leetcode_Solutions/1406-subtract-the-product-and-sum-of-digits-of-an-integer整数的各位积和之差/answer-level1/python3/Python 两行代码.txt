```python
from functools import reduce
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        nums = [int(s) for s in str(n)]
        return  reduce(lambda a, b : a * b, nums) - reduce(lambda a, b : a + b, nums)
```
