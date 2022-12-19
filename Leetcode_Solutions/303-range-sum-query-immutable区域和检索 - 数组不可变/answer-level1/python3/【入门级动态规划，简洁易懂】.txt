### 解题思路
基本思路：根据提示多次调用，想到将前k项之和（0<=k<=max）记录在表中，当调用计算函数时，只需找到对应记录位置相减即可
说一下两个易错点：
1. 一开始我将动态规划的代码写到计算函数中去了，这是错误的，因为每次调用该函数都会重复计算，导致超时
2. sums表中初始化一开始设置的是nums[0],这样会导致一种情况即nums为空时出错，所以初始化为0，后续只要理解思路就可以设置相应的变量范围

### 代码

```python3
class NumArray:
    # 思路：多次调用，如果暴力解答，可能超时，所以可以事先将前n项之和计算出来，相减就是所求结果
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.sums = [0]

        for t in range(0, len(self.nums)):
            # 当前项加上前一步计算出来的和，该处体现动态规划思想
            self.sums.append(self.nums[t] + self.sums[t])
        
    # 不能把动态规划的东西写在这个函数中，因为多次调用会导致多次计算前n项之和
    def sumRange(self, i: int, j: int) -> int:
            return self.sums[j+1] - self.sums[i]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```