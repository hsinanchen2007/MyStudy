用一个变量记录能够达到的最远的位置
对原数组做遍历
每一步去更新这个位置 futherest = max(futherest,i+nums[i])
如果这个位置能超过最后一位，则返回True
如果到了某个i，i>futherest
则返回False
代码很简单

```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) <= 1: return True
        futherest = 0
        
        for i in range(len(nums)-1):
            if i > futherest:
                return False
            futherest = max(i+nums[i],futherest)
            if futherest >= len(nums) - 1:
                return True
        return False
```
