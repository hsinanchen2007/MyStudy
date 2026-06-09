### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
       
        store = [0] * (len(nums) + 1)
        for num in nums:
            store[num] = 1
         
        return store.index(0)
```