### 解题思路
找第一个缺失后的值

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        if not nums:
            return None
        left = 0
        right = len(nums)#因为一个元素缺失，会导致数组长度-1，故而原数组长度比nums多1
        while left<right:
            mid = (left+right) // 2
            if mid == nums[mid]:#当mid==nums[mid]时，表明缺失的数据在它后面，且不包括它
                left = mid +1
            elif nums[mid] > mid:#当>时，表明缺失的数据在它左边，也有可能就是mid自己，故而right=mid,而不是mid-1
                right = mid
        return left

                

```