### 解题思路
题目要求 求是否有递增的三元子序列。可以维护两个变量 一个 最小值 s 一个中间值 m
当遍历整个数组的时候 如果遇到小于s 并且小于 m的时候 就更新最小值，如果大于s 小于m 就更新中间值， 如果在遇到大于s 和大于m 那么就代表找到这组递增三元子序列 返回True 

### 代码

```python
import sys
class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)<2 :
            return False
        s=sys.maxsize-1
        m=sys.maxsize
        for i in nums:
            if i < s and i < m:
                s = i
            elif i>s and i<m:
                m = i
            elif i>s and i>m:
                return True
        return False
```