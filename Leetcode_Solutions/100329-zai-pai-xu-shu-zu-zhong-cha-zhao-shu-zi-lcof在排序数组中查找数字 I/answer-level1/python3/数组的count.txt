
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        counts =0
        for n in nums:
            if n==target:counts+=1
        return counts
        # return nums.count(target)
            
```