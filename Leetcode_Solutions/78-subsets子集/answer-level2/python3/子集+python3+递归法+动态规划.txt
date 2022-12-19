### 解法1：递归
分析可以得出：
1. `f([1,2]) = [[], [1,2], [2], [1]]`;
2. `f([1,2,3]) = [[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]`
2. f([1,2,3])是在f([1,2])的元素基础上，对每个元素多加一个3

代码如下：
```python []
class Solution(object):
    def subsets(self, nums):
        if nums ==[]:
            return [[]]
        return self.subsets(nums[:-1]) + [i+[nums[-1]] for i in self.subsets(nums[:-1])]
```

### 解法2：动态规划
跟上面递归的想法类似，就是找出当前的结果跟前一个结果的关系：

  `dp[i] = dp[i-1] + [each+[nums[i]] for each in dp[i-1]]`

代码如下：
```python []
class Solution(object):
    def subsets(self, nums):
        dp = [[]]
        for i in range(len(nums)):
            dp = dp + [each+[nums[i]] for each in dp]
            
        return dp 
        
```
