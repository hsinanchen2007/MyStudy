

**思路一：** 二分法

时间复杂度：$O(nlogn)$

备注：对于如何找二分法的判断条件，我一般是用特殊例子，举个例子 `nums = [0, 2, 3]`

我们发现当 `mid = 1, nums[mid] > mid`，这时候我们想把 `right` 移过来。

```python [-Python]
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        left = 0
        right = len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > mid:
                right = mid 
            else:
                left = mid + 1
        return left
```

**思路二：** 求和法

关键在于 **索引号** 和 **数** 建立关系

假如我们数组不缺任何数 `[0, 1, 2]`，我们有 $0 - nums[0] + 1 - nums[1] + 2 - nums[2] = 0$。即使我们打乱数据 `[2, 0, 1]`, $0 - nums[0] + 1 - nums[1] + 2 - nums[2] = 0 - 2 + 1 - 0 + 2 - 1 = 0$。

所以，在不缺少任何数字，不管我们如何打乱数组，我们都有 **每个数 索引号和数相减的和都为零**，

当我们缺失一个值的时候，比如 `[3, 0, 1]`，假设缺失值位 `x`， 得 `[3,0,1,x]`，有 $0 - nums[0] + 1 - nums[1] + 2 - nums[2] + 3 - nums[3] = 0$

即 `0 - 3 + 1 - 0 + 2 - 1 + 3 - x = 0`，求出 `x = 2`

总结公式：得 $x = \sum _{n = 0}^{len(nums) - 1}{(idx - nums[idx])} + len(nums)$

时间复杂度 : $O(n)$

所以有：

```python [-Python]
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = len(nums)
        for idx, num in enumerate(nums):
            res += idx - num
        return res
```

**思路三**：位运算

其实求和一个道理 `a ^ b ^ b = a`

时间复杂度：$O(n)$

```python [-Python]
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0
        for idx, num in enumerate(nums):
            res = res ^ idx ^ num
        return res ^ len(nums)
```

