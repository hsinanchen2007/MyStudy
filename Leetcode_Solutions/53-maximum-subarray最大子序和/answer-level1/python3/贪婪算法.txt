### 解题思路
采用贪心算法来解，用到两个和，一个当前和，一个最大和

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        maxSum = currentSum = nums[0]
        for i in range(1, n):
          if currentSum + nums[i] > nums[i]:
            maxSum = max(maxSum, currentSum + nums[i])
            currentSum = currentSum + nums[i]
          else:
          # 当当前和小于下一个元素，则从下一个元素开始重新求和
             maxSum = max(maxSum, currentSum, currentSum+nums[i], nums[i])
             currentSum = nums[i] 
        return maxSum
```