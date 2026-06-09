

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        if len(set(nums)) < 3:
            return max(sorted(list(set(nums))))
        
       
        return sorted(list(set(nums)), reverse=True)[2]
```