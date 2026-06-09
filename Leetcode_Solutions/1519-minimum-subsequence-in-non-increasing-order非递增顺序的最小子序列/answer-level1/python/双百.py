### 解题思路
小到大排序，nums每次把最大值给res，计算和的大小

### 代码

```python
class Solution(object):
    def minSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums = sorted(nums)
        res = []
        while 1:
            res.append(nums.pop())
            if len(nums) == 0 or sum(res[:]) > sum(nums[:]):
                return res
```
![image.png](https://pic.leetcode-cn.com/f6657406b4ab42e479ddc7f1b01216d6bd26e61ecfe7a55b3e8c2f0371915c50-image.png)
