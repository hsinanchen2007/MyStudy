### 解题思路
递归
![image.png](https://pic.leetcode-cn.com/4ee6b270229acacb519e11d941390db2703fad541b8dad2c639a6b0b882e2382-image.png)

### 代码

```python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 1: return [nums]

        n = len(nums)
        res = []

        for i, num in enumerate(nums):
            rest = nums[:i] + nums[i+1:]
            for j in self.permute(rest):
                res.append([num]+j)

        return res

```