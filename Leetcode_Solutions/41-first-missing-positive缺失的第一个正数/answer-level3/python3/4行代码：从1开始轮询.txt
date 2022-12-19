初学者比较直观的方法：从最小正整数1开始轮询，若i在nums中则+1
![26通过.png](https://pic.leetcode-cn.com/392ecd512ab117f94cb116ec42599483769f44d1ea625c0bee8e24c7984680f8-26%E9%80%9A%E8%BF%87.png)

代码：

    class Solution:
        def firstMissingPositive(self, nums: List[int]) -> int:
            i = 1
            while i in nums:
                i += 1
            return i