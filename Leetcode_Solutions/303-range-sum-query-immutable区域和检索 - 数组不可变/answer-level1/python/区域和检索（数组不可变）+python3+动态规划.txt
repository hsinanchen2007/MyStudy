### 动态规划
这题一开始暴力解，会超时，因此改用动态规划，时空复杂度很好，均超过了95%的提交。

基本思路: 先求从0到每一个数的和，存入一个数组，最后求i到j 的和直接相减就可以了。代码如下：
```
class NumArray:

    def __init__(self, nums: List[int]): 
        self.nums = nums
        sum_=0
        n = len(nums)
        target =[]
        for i in range(n):
            sum_ += nums[i]
            target.append(sum_)
        self.target = target
    def sumRange(self, i: int, j: int) -> int:            
        return self.target[j]-self.target[i]+self.nums[i]
```