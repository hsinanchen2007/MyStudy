因为乘法表中每行都是有序的，总共`m`行`n`列，最小值为`1`，最大值为`m*n`，在此区间进行二分查找。

每次统计小于等于`mid`的数有多少个(`cnt`)。小于k个，说明`mid`小于`target`，区间右移。直到遇到第一个`cnt`大于等于k个的数则为答案。

如何统计比mid小的数有多少个？
>形式化第i行的数为 `[1*i, 2*i, 3*i, ..., k*i, ..., n*i]`，每一行都有n个数。
假设此时第k个数 `k*i` 小于等于`mid`，所以`k*i <= mid`, `k = mid // i`，说明这行比小于等于`mid`的数有`k`个。
当 `k<n`时，说明此行有`k`个数小于等于`mid`，当 `k>=n` 时，说明此行的`n`个数都小于等于`mid`。
最后遍历所有行，统计所有小于等于`mid`的数都多少个。


```python
class Solution:
    def findKthNumber(self, m, n, k):
        l, r = 1, m*n
        while l < r:
            mid = l + r >>1
            cnt = 0  # 统计乘法表中小于等于mid的值的总数
            for i in range(1, m + 1):  # 遍历每一行，统计。
                cnt += min(mid//i, n)
            if cnt < k:
                l = mid + 1
            else:
                r = mid
        return l
```
