依次计算数组的前1个数，前2个数，前3个数......前n个数 的前缀和，将它们置于一个排好序的列表$L$内

现在计算出了前n+1个数的前缀和$S_{n+1}$，我们考虑以索引 n + 1 结束的所有区间的区间和。
是不是能表示成：
$S_{n+1} - a_1, S_{n+1} - a_2, ....S_{n+1} - a_n$ 其中 $a_i$ 在列表$L$内
我们的目的是查找上述$n$个数，落在 $[lower, upper]$ 的个数，由于列表是排好序的，可以使用**二分**来做

```python
import bisect
from itertools import accumulate

class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        data = []
        res = 0
        for s in accumulate(nums):
            res += bisect.bisect(data, s - lower) - bisect.bisect_left(data, s - upper)
            bisect.insort(data, s)
            if lower <= s <= upper:  # 在之前二分统计的时候没有吧这个区间统计上去
                res += 1
        return res
```
由于要进行二分插入，所以总的时间复杂度还是$O(n^2)$，但是平均来说还是比暴力法更快一些