### 解题思路
奇数指针从零开始，偶数指针从尾开始。

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        n = len(nums)
        even = 0
        odd = n-1
        while(even < odd):
            while((nums[even]%2 == 1) and (even < n-1)):
                even += 1
            while(nums[odd]%2 == 0 and odd >-1):
                odd -= 1
            if(even < odd):
                nums[even],nums[odd] = nums[odd],nums[even]
            
        return nums
```