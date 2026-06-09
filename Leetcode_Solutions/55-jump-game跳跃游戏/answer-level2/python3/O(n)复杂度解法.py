#### 递归式解法
```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        
        for shift in range(1, len(nums)):
            if nums[len(nums)-1-shift] >= shift:
                if shift == len(nums) - 1:
                    return True
                return self.canJump(nums[:-shift])

        return False
```
复杂度高，超过时间限制

#### O(n)复杂度解法
```python
class Solution(object):
    def canJump(self, nums):
        if not nums:
            return True
        
        maxReach = nums[0]
        now = 0
        while maxReach >= now:
            maxReach = max(maxReach, now + nums[now])
            now += 1
            if maxReach >= len(nums) - 1:
                return True
        
        return False
```
从第一项开始更新可达区域，直至可达末端
> 初始化可达区域nums[0]  
向前一步，更新可达区域为max(1+nums[1], maxReach)  
判定是否可达末端  
  是： 返回  
  否： 继续循环  
判定是否能继续往前走  
  是:    继续  
  否:    返回  