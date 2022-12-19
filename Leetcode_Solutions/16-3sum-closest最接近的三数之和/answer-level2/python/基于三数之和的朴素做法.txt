### 解题思路
看来不咋样
基本就是把0视作target，并根据这个把代码里面的判断条件改一遍
### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        l = len(nums)
        if l < 3:
            return None
        nums.sort()
        res = nums[0]+nums[1]+nums[2]
        for i in range(l):
            if nums[i]>target and nums[i]>0:
                if i == 0:
                    return res
                else:
                    temp = nums[i]+nums[1]+nums[2]
                    if abs(res - target) < abs(temp-target):
                        return res
                    else:
                        return temp
            left = i + 1
            right = l - 1
            while left<right:
                temp = nums[i]+nums[left]+nums[right]
                if abs(temp-target) < abs(res-target):
                    res = temp
                if temp-target < 0:
                    left+=1
                elif temp-target > 0:
                    right-=1
                else:
                    return target
        return res

```