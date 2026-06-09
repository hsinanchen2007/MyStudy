![image.png](https://pic.leetcode-cn.com/242699980fb8f516eda06692b42632d16c3c8933634a2800ff71a08f5aa8e5fe-image.png)


```
'''
单调栈找每一个数右边第一个比它小的数值所在位置就可以得出以这个
数值为起点的合法序列个数，累加所有个数可得出最后答案
'''

from typing import List
class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        stack = []
        ans = 0
        for i, val in enumerate(nums):
            while len(stack) > 0 and val < stack[-1][1]:
                ans += i - stack[-1][0]
                stack.pop(-1)
            stack.append((i, val))

        # 还保存在栈里面的节点，右边没有比其小的节点，所以右边界是len(nums)
        for pos, _ in stack:
            ans += len(nums) - pos
        return ans
```
