### 解题思路
此题分两种情况，一种是偶数位都是低的，另一种是奇数位都是低的。
由于数字只能够降低，对于第一种情况可以发现由于偶数位要比两边都要低，所以降低奇数位的数字没有任何收益，所以我们只需要考虑偶数位的数字降低到比左右两边数字的最小值还要小就可以了，不用改动奇数位的任何数字。第二种情况同理。

### 代码

```python
class Solution(object):
    def movesToMakeZigzag(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1 or len(nums) == 2:
            return 0
        result1 = 0
        result2 = 0
        for i in range(1, len(nums), 2):
            left = nums[i-1]
            if i < len(nums) - 1:
                right = nums[i+1]
            else:
                right = float('inf')
            if nums[i] >= min(left, right):
                result1 += nums[i] - min(left, right) + 1
        for j in range(0, len(nums), 2):
            if j == 0:
                left = float('inf')
            else:
                left = nums[j-1]
            if j < len(nums) - 1:
                right = nums[j+1]
            else:
                right = float('inf')
            if nums[j] >= min(left, right):
                result2 += nums[j] - min(left, right) + 1
        return min(result1, result2)



```