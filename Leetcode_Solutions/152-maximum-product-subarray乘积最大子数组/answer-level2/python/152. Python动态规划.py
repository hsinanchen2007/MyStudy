### 解题思路
使用动态规划解决这道题，思路不再赘述。
由于可能存在负数，所以不能只保存最大值，还需要保存最小值，这样在包括偶数个负数的子序列时仍然可以获得正确的答案。
拓展：这里空间复杂度是O(n)的，可以改成O(1)的。

### 代码

```python
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        dp_max = [nums[0]] + [0] * (length - 1) # dp_max[i]记录以nums[i]为结尾的子序列乘积最大值
        dp_min = [nums[0]] + [0] * (length - 1) # dp_min[i]记录以nums[i]为结尾的子序列成绩最小值
        max_num = nums[0]
        for i in range(1, length):
            if nums[i] >= 0:
                dp_max[i] = max(nums[i] * dp_max[i - 1], nums[i])
                dp_min[i] = min(nums[i] * dp_min[i - 1], nums[i])
            else:
                dp_max[i] = max(nums[i] * dp_min[i - 1], nums[i])
                dp_min[i] = min(nums[i] * dp_max[i - 1], nums[i])
            if dp_max[i] > max_num:
                max_num = dp_max[i]
        return max_num
```