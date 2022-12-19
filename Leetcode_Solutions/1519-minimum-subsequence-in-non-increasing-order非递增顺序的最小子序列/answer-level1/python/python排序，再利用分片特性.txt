### 解题思路
![image.png](https://pic.leetcode-cn.com/57aa5b7e7bf8b03feb3f799bc448301686e67ca02a86f72ee05d186ffdfc6832-image.png)

数组非递增排序，再利用分片特性
遍历时，长度+1的原因是对于数组内只有一个元素或两个相同元素的数组，应返回整个数组

### 代码

```python
class Solution(object):
    def minSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort(reverse=True)
        for i in range(len(nums) + 1):
            if sum(nums[:i]) > sum(nums[i:]):
                return nums[:i]

```