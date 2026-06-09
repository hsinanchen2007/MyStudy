### 解题思路
![image.png](https://pic.leetcode-cn.com/ae80c9e221a46eb13a38e384f4222ba001210d91470d402f763d02677dc07d9f-image.png)

参考大佬的

### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        res = nums[0]
        max_ = nums[0]
        for i in range(1,size):
            # if res < 0:
            #     res = nums[i]
            # else:
            #     res = res + nums[i]
            res = max(nums[i], res + nums[i])
            max_ = max(max_, res)
        return max_
```