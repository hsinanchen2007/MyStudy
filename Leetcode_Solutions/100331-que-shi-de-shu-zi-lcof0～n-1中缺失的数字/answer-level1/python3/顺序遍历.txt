- 递增且完整序列是0-n-1,那只要顺序遍历0-n-1，nums缺失的位置的数据不等于遍历的这个数,那么i就是这个缺失的数
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        if nums is None or nums==[]:return None
        nums.append(None)
        for i in range(len(nums)+1):
            if nums[i]!=i:return i
            
```
