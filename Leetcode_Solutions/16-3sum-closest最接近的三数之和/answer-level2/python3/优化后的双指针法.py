### 解题思路
在之前的基础上加上了重复检测，效果有点显著（因为样例里的重复项着实多）

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
                    while(left<right and nums[left]==nums[left-1]): # ！！！！！！！
                        left+=1
                elif temp-target > 0:
                    right-=1
                    while(left<right and nums[right]==nums[right+1]):
                        right -= 1
                else:
                    return target
        return res

```