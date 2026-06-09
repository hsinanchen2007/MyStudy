
2020.3.24
已根据评论区同学们包括@五行缺你@wahahaLI的建议作出修改，感谢各位。

另外补充评论区中@蜗蜗蜗蜗蜗蜗牛 同学的排序后的二分查找算法，也一并更新。

```python []
import bisect

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index = len(nums) - 1
        while index > 0:
            if nums[index] > nums[index-1]:
                break
            index -= 1
        
        if index > 0:
            nums[index:] = sorted(nums[index:])
            swap_index = bisect.bisect(nums, nums[index-1], lo=index)
            nums[swap_index], nums[index-1] = nums[index-1], nums[swap_index]
        else:
            nums.reverse()
```

***

参考[执行用时1ms的题解](https://leetcode-cn.com/problems/next-permutation/solution/zhi-xing-yong-shi-1msde-ti-jie-by-ywd-2-119/)这篇题解，然后我给出python版的解法。

题解中的解题思路：

> 设计思路：
    1.从数组右侧向左开始遍历，找是否存在nums[i]>nums[i-1]的情况，
    2.如果不存在这种nums[i]>nums[i-1]情况 ，for循环会遍历到i==0（也就是没有下一个排列），此时按题意排成有序Arrays.sort()
    3.如果存在，则将从下标i到nums.length()的部分排序，然后在排过序的这部分中遍历找到第一个大于nums[i-1]的数，并与nums[i-1]交换位置

代码如下：

```python []
#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#

# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:
                nums[i:] = sorted(nums[i:])
                for j in range(i, len(nums)):
                    if nums[j] > nums[i-1]:
                        nums[j], nums[i-1] = nums[i-1], nums[j]
                        break
                return
        nums.sort()

# @lc code=end


```

- 265/265 cases passed (56 ms)
- Your runtime beats 25.57 % of python3 submissions
- Your memory usage beats 9.15 % of python3 submissions (13.4 MB)