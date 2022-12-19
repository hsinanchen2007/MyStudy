可以使用单调队列 deque ,也可以使用单调栈，本质都是一样的思想。
```
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        # 循环数组，使用i%n表示数组索引，不用复制两个一样的数组
        # 还是单调栈的思路，其实也是双端队列维护qmax的思想，具体可以参考LeetCode生成窗口最大值数组
        n = len(nums)
        res = [0 for i in range(n)]
        stack = []
        # 倒着遍历
        for i in range(n*2-1,-1,-1):
            while stack and stack[-1] <= nums[i%n]:
                stack.pop()
            if i < n:
                res[i] = stack[-1] if stack else -1 
            stack.append(nums[i%n])
        return res

```
