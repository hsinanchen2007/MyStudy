### 解题思路
对于每一个数，若前面的子数组和为正，则加上前面的子数组作为新的子数组，若为负则保留自身作为新的子数组；
每次遍历都与当前最大子数组和做比较，保留较大者。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = tempSum= nums[0]
        for num in nums[1:]:
            tempSum = max(num, num + tempSum)
            maxSum = max(maxSum, tempSum)
        return maxSum

```