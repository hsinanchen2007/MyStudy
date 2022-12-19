### 解题思路
与3Sum思路一致，双指针
要注意指针的边界问题

### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []
        nums.sort()
        res = []

        for i in range(len(nums)-3):
            if i > 0 and nums[i-1] == nums[i]: # 遇到相同值即跳过
                continue
            for j in range(i+1, len(nums)-2):
                if j-1 != i and nums[j-1] == nums[j]: # 遇到相同值即跳过
                    continue
                left = j+1
                right = len(nums)-1
                while left < right:
                    if nums[i]+nums[j]+nums[left]+nums[right] == target:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        # 同样遇到相同值指针后移/前移，注意left与right的指针边界
                        while left+1<len(nums) and nums[left+1] == nums[left]:
                            left += 1
                        while right-1>j and nums[right-1] == nums[right]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif nums[i]+nums[j]+nums[left]+nums[right] < target:
                        left += 1
                    else:
                        right -= 1
        return res
                    

```