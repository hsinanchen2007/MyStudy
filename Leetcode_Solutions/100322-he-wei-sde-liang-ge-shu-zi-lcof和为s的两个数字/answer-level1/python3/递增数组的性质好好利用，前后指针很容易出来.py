### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # hash map
        # if not nums:
        #     return []
        # nums_dict = {}
        # for i in range(len(nums)):
        #     if target-nums[i] not in nums_dict:
        #         nums_dict[nums[i]] = i
        #     else:
        #         return nums[i],target-nums[i]

        if not nums:
            return []
        #双指针法更简单
        l, r = 0, len(nums)-1
        while l < r:
            if nums[l] + nums[r] == target:
                return nums[l],nums[r]
            elif nums[l] + nums[r] < target:
                l += 1
            else:
                r -= 1


```