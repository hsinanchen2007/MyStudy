```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        count = 1
        ans = None

        for num in nums:
            if ans != num:
                count -= 1
            else:
                count += 1
            if count == 0:
                ans = num
                count = 1
        
        return ans 
        
    def majorityElement1(self, nums: List[int]) -> int:
        k = (len(nums)+1) // 2
        start, end = 0, len(nums)-1
        while start < end:
            j = start
            for i in range(start, end+1):
                if nums[i] >= nums[end]:
                    nums[i], nums[j] = nums[j], nums[i]
                    j += 1
            if j == k:
                return nums[j-1]
            elif j < k:
                start = j
            else:
                end = j-2
        return nums[start] 
```