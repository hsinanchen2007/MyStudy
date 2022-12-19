

#### 1. 暴力法 - 在每次调用时求解
##### 复杂度分析
 - 时间复杂度：
   - 每次查询时间为O(N) - 每次查询时进行长度为j + 1 - i的线性求和运算，其中j + 1 - i最大值为N
   - 预计算时间为O(1)
 - 空间复杂度：O(1) - self._nums是对nums的引用

```Python
from typing import List


class NumArray(object):

    def __init__(self, nums: List[int]):
        self._nums = nums

    def sumRange(self, i: int, j: int) -> int:
        return sum(self._nums[i:j + 1])
```

#### 2. 缓存
##### 思路
 - 将每位求和的值保存在新的数组中，每次求和使用sum累加
##### 复杂度分析
 - 时间复杂度：每次查询时间为O(1)，预计算（缓存）时间为O(N^2)
 - 空间复杂度：O(N) - 缓存了长度为N的求和值数组
```Python
class NumArray(object):

    def __init__(self, nums: List[int]):
        self._sums = [sum(nums[0:i + 1]) for i in range(len(nums))]

    def sumRange(self, i: int, j: int) -> int:
        return self._sums[j] if i == 0 else self._sums[j] - self._sums[i - 1]
```

#### 3. 动态规划 + 缓存
##### 思路
 - 状态转移方程：dp[i] = dp[i - 1] + nums[i - 1]; res = dp[j + 1] - dp[i];
 - 将每位求和的值保存在参数数组中，其中，每位和为上一位和加上原位数的值
##### 复杂度分析
 - 时间复杂度：每次查询时间为O(1)，预计算时间为O(N)
 - 空间复杂度：O(1) - self._nums是对nums的引用
```Python
class NumArray(object):

    def __init__(self, nums: List[int]):
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        self._sums = nums

    def sumRange(self, i: int, j: int) -> int:
        return self._sums[j] if i == 0 else self._sums[j] - self._sums[i - 1]
```







