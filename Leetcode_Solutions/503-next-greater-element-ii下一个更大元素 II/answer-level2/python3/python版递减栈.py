reference：
[https://leetcode-cn.com/problems/daily-temperatures/solution/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo/](https://leetcode-cn.com/problems/daily-temperatures/solution/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo/)

用上述思路遍历两次列表

```
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        nums = nums + nums
        stack = []
        res = [-1] * len(nums)

        for i in range(len(nums)):
            while stack and nums[i] > nums[stack[-1]]:
                small = stack.pop()
                res[small] = nums[i]
            stack.append(i)

        return res[:len(res)//2]
```
