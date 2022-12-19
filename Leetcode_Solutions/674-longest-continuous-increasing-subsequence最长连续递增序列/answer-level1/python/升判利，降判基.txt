### 解题思路
升判利，降判基

### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return 1
        pre = nums[0]
        a = b = 0
        max_len = 1
        for i in range(1,n):
            if nums[i] > pre:
                b = i
                max_len = max(max_len,b - a + 1)
            else:
                a = i 
            pre = nums[i]
        return max_len
```