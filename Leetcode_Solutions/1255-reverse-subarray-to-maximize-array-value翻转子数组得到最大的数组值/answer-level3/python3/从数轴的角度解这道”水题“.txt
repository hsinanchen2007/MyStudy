### 解题思路
翻转子数组，子数组内部计算数组值完全相同，唯一存在的差异就在子数组的**两个端点**。

这时分两种情况：
- 其中一个端点就是`nums`的端点：这时线性扫一遍其余点即可；
- 两个端点均不是`nums`的端点：将四个点(子数组的端点`L`、`R`和`L-1`、`R+1`)按大小标记在数轴上，很容易发现只有当`[nums[L], nums[L-1]]`和`[nums[R], nums[R+1]]` 不相交时，翻转`[L, R]`子数组才能为数组值增加2倍中间不相交的间距；这时将每个`(nums[i], nums[i+1])`排好序，直接和”最大“值比即可；

两种情况都是`O(n)`.

P.S.: 这道题其实真不难:\ 我好菜啊

### 代码

``` python
class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        n = len(nums)
        arr = sorted([(min(a, b), max(a, b)) for a, b in zip(nums[:-1], nums[1:])])
        res = base = sum(mx - mn for mn, mx in arr)
        head, tail = nums[0], nums[-1]
        # case 1: 
        if n > 2:
            res = max(res, base + abs(head - nums[2]) - abs(nums[1] - nums[2]))
            res = max(res, base + abs(tail - nums[-2]) - abs(nums[-2] - nums[-3]))
        for i in range(1, n-1):
            v, m, p = nums[i], nums[i-1], nums[i+1]
            res = max(res, base - abs(v - p) + abs(head - p))
            res = max(res, base - abs(v - m) + abs(tail - m))
        # case 2:
        for idx, (mn, mx) in enumerate(arr):
            res = max(res, base + 2 * (arr[-1][0] - mx))
        # for i in range(n):
        #     for j in range(i+1, n):
        #         nums[i: j+1] = nums[i: j+1][::-1]
        #         aux = sum(abs(a - b) for a, b in zip(nums[1:], nums[:-1]))
        #         nums[i: j+1] = nums[i: j+1][::-1]
        #         print(i, j, aux)
        return res
```