### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        '''
        return nums.index(target) if target in nums else sorted([*nums,target]).index(target)
        '''
        '''
        if target in nums:
            return nums.index(target)
        else:
            nums.append(target)
            nums.sort()
            return nums.index(target)
        '''
        '''
        return len([i for i in nums if i<target])
        '''
        '''
        for i,v in enumerate(nums):
            if v>=target:
                return i
        return len(nums)
        '''
        '''
        left = 0
        right = len(nums)-1
        #right = len(nums)
        while left<=right:
        #while left<right:
            mid = left+(right-left)//2
            if nums[mid]==target: return mid
            elif nums[mid]<target:
                left=mid+1
            else:
                right=mid-1
                #right = mid
        return left
        '''
        left = 0
        right = len(nums)
        while left<right:
            mid = left+(right-left)//2
            if nums[mid]<target:
                left = mid+1
            else:
                assert nums[mid]>=target
                right = mid
        return left
```