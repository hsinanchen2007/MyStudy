### 解题思路
需要同时记录以当前整数为结尾的连乘序列的最大值与最小值，因为当前的dp_max|min[i]记录的数依赖于对方前一步计算的dp_min|max[i-1]
以当前数结尾的连乘序列最大取值有三种情况：
1. 前一步的最大值（+）*当前值（+）
2. 如果前一步最大值为-，且当前值为+，则最大值仅为当前值（+）
3. 前一步的最小值（-）*当前值（-）
其他组合的情况都不会取到比上述情况更大的值，所以可以以上述情况为全集取其中最大值

### 代码

```python3
class Solution:
    # 需要同时记录当前的最大值和最小值
    # 当前的最大值=前一步的最大值（+）*当前值（+）或者前一步的最小值（-）*当前值（-）
    #                         （-） 当前值（+） 
    # 当前的最小值=前一步的最大值（+）*当前值（-）或者前一步的最小值（-）*当前值（+）
    #                                                          （+） 当前值（-）
    # dp[i] = max(dp[i-1]*nums[i],nums[i])
    def maxProduct(self, nums: List[int]) -> int:
        t = len(nums)
        # 初始化
        dp_max = [0]*t
        dp_min = [0]*t
        dp_max[0] = nums[0]
        dp_min[0] =nums[0]
        max_val = nums[0]
        for i in range(1,t):
            dp_max[i] = max(nums[i],nums[i]*dp_max[i-1],nums[i]*dp_min[i-1])
            dp_min[i] = min(nums[i],nums[i]*dp_min[i-1],nums[i]*dp_max[i-1])
            if dp_max[i] > max_val:
                max_val = dp_max[i]
        return max_val

        
```