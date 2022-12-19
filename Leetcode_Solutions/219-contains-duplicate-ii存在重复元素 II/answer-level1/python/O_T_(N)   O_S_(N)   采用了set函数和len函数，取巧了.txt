### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if(len(nums) == len(set(nums))): return False
        if(k>=len(nums)):return (len(nums) != len(set(nums)))
        for i in range(len(nums)-k+1):
            if(len(nums[i:k+i+1])!=len(set(nums[i:k+i+1]))):
                return True
        return False
```