### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # 前缀和思想
        n = len(nums)
        preSum = dict()
        # base case 如果初始的时候sum_i - k = 0,则preSum[0]应该为 1
        preSum[0] = 1
        sum_i = 0
        res = 0
        for i in range(n):
            sum_i += nums[i]
            sum_j = sum_i - k
            if sum_j in preSum:
                res += preSum.get(sum_j)
            preSum[sum_i] = preSum.get(sum_i,0) + 1
        return res
```