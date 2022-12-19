### 解题思路
* ![missing-num.png](https://pic.leetcode-cn.com/fb96a2be184bc76e7cb9db7acaee16ab2871924394b31c398236d8405f2745cb-missing-num.png)

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        实际累加和 - 理论累加和 = 缺失项
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return 1 - nums[0]
        max_num = 0
        sum_num = 0
        for i in nums:
            if i > max_num:
                max_num = i
            sum_num += i
        if len(nums) == max_num + 1:
            return len(nums)
        # sum = (n1 + nn) * n / 2
        return (0 + max_num) * (1 + max_num) / 2 - sum_num
```
