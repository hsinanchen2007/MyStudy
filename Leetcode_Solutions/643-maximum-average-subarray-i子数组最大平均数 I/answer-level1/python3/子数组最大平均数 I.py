### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        if k > len(nums) or k == 0:
            return 0

        total = sum(nums[0:k])
        maxSum = total

        for i in range(k, len(nums)):
            total -= nums[i-k]
            total += nums[i]
            maxSum = max(maxSum, total)
        return maxSum / k


```