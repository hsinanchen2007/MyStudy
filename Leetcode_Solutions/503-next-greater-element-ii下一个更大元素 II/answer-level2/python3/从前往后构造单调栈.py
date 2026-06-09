```
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        """
           可以考虑将数组扩充一倍, 然后不停的将栈中更早的元素pop掉

           每个元素仅仅只会出栈一次, 单可能入栈多次
        """
        size = len(nums)
        # 扩大数组, 其实也不用扩大
        res = [-1 for _ in range(size)]
        for i in range(len(nums)):
            nums.append(nums[i])
        
        stack = []

        for ix, value in enumerate(nums):
            if not stack or nums[stack[-1]] >= value:
                stack.append(ix)
                continue
            
            while stack and nums[stack[-1]] < value:
                res[stack[-1]%size] = value
                stack.pop()
            
            stack.append(ix)
        
        return res
```
