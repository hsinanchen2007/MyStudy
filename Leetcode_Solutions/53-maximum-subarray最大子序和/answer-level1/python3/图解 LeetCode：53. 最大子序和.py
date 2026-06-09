```
                         初始值：        0           8
                               maxContinuousSum  maxSum
                              到当前值的最大连续和 最大子序和
  [8 , -19 , 5 , -4 , 20]  |            8           8
   -                       |
   ^                       |
  [8 , -19 , 5 , -4 , 20]  |           -11          8
   =------                 |
        ^                  |
  [8 , -19 , 5 , -4 , 20]  |            5           8
   -         -             |
             ^             |
  [8 , -19 , 5 , -4 , 20]  |            1           8
   -         ------        |
                  ^        |
  [8 , -19 , 5 , -4 , 20]  |            21          21
             ===========   |       
                      ^
```
### 思路

- 标签：`正数增益`
- 最大子序和：最大（连续）子序和
- 需要记录当前值前面的最大子序和，和**到当前值的最大连续和**。
- 正数增益：当前值只有加一个正数（最大连续和），才会比当前值大
- 时间复杂度：O(n)
- 空间复杂度：O(1)

### 代码

```python
## Python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        maxContinuousSum = 0 # 到当前值的最大连续和
        for num in nums:
            if maxContinuousSum > 0:
                maxContinuousSum = maxContinuousSum + num
            else:
                maxContinuousSum = num
            maxSum = max(maxSum, maxContinuousSum)
        return maxSum
```

