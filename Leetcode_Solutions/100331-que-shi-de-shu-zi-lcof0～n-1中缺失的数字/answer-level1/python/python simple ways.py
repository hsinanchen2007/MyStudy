### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        '''
        #1. len(nums)
        for i in range(len(nums)+1):
            if i not in nums:
                return i
        '''
        '''
        #2. set
        allnums = set(list(range(len(nums)+1)))
        nums = set(nums)
        return list(allnums-nums)[0]
        '''
        '''
        return list(set([i for i in range(len(nums)+1)])-set(nums))[-1]
        '''

        '''
        #3. 二分
        i, j = 0, len(nums)-1
        while i<=j:
            m = (i+j)//2
            if nums[m]==m: i = m+1
            else: j = m-1
        return i
        '''
        '''
        #4. math
        n = len(nums)
        return (n+1)*n//2 - sum(nums)
        '''
        if len(nums) == 1:
            if nums[0] > 0:
                return nums[0] - 1
            return nums[0] + 1
        for i in range(1, len(nums)):
            if nums[i] - nums[i-1] != 1:
                return nums[i] - 1
        else:
            if nums[0] != 0:
                return nums[0] - 1
            return nums[i] + 1
```