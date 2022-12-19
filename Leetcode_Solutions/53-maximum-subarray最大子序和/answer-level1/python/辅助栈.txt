```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:return 0
        stack=[nums[0]]
        for i in range(1,len(nums)):
            if stack[len(stack)-1]<0:
                stack.append(nums[i]) # 如果栈顶元素大于0则相加，否则取本身，剑指offer原题
            else:
                stack.append(stack[len(stack)-1]+nums[i])
        return max(stack)
            
```
