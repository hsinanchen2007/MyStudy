### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        odd = filter(lambda x: x % 2 == 1,nums)
        even = filter(lambda x: x % 2 == 0,nums)
        
        return list(odd) + list(even)
```