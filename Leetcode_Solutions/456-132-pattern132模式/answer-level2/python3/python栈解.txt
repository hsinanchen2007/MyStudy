参考CSDN上博主的思路写的栈解。
```
import sys
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(set(nums)) < 3:
            return False
        third = -sys.maxsize
        stack = [nums[-1]]
        n = len(nums)
        for each in range(n-2, -1, -1):
            if nums[each] < third:
                return True
            if nums[each] <= stack[-1]:
                stack.append(nums[each])
                continue
            while (nums[each] > stack[-1]):
                third = stack.pop()
                if stack == []:
                    break
            stack.append(nums[each])
        return False
```
