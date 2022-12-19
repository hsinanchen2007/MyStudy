### 解题思路
贪婪算法
复杂度都是O(n)
还是分治吧，介于测试集不太大，所以看上去执行效果还过得去

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        curSum = maxSum = nums[0]
        for i in range(1, n):
            curSum = max(nums[i], curSum + nums[i])
            maxSum = max(maxSum, curSum)    
        return maxSum
```