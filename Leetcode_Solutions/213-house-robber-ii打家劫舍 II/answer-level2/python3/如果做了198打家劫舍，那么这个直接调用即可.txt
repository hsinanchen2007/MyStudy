只是多了一个分类讨论，要不要打劫第一家。。[1,2,3,4,5] 拆成[2,3,4,5] 和 [1,2,3,4] 输入到198打家劫舍里，然后求最大值。
``` 
class Solution:
    def rob(self, nums: List[int]) -> int:
                
        if not nums:
            return 0
        
        if(len(nums) == 1):
            return nums[0]
        
        if(len(nums) == 2):
            return max(nums[0],nums[1])
        
        if(len(nums) == 3):
            return max(nums[0],nums[1],nums[2])
        
        return max(self._rob(nums[0:len(nums)-1]),self._rob(nums[1:]))
        
        
    def _rob(self,nums):  # 198打家劫舍
        
        if not nums:
            return 0
        
        max_money = [i for i in nums]
        
        if(len(nums) == 1):
            return max_money[0]
        
        max_money[1] = max(max_money[0],max_money[1])
        
        
        for i in range(2,len(nums)):
            
            max_money[i] = max(max_money[i-2] + nums[i],max_money[i-1])
            
        return max_money[len(nums) - 1]
```