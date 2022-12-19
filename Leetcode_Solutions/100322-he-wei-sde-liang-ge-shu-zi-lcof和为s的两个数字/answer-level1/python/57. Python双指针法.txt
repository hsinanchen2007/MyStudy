### 解题思路
对于这道题我马上的想法是单词遍历序列然后用哈希表记录之前出现过的数字，这种方法时间和空间复杂度都是O(n)。
但是看了题解之后觉得自己还是思维不够活跃，可以用两个指针p, q分别从首尾开始遍历，会出现三种情况：
（1）nums[p] + nums[q] == target。返回答案。
（2）nums[p] + nums[q] < target。p指针向右移动一位。
（3）nums[p] + nums[q] > target。q指针向左移动一位。

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        p = 0
        q = length - 1
        while nums[p] + nums[q] != target:
            if nums[p] + nums[q] > target:
                q -= 1
            else:
                p += 1
        return [nums[p], nums[q]]
```