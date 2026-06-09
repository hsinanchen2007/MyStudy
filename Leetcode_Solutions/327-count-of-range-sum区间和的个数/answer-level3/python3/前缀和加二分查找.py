### 解题思路
-   二分法
-   首先经过观察，如果能够得到任意两个范围之间的数字之和，直接统计在`[lower,upper]`，但是这种效率不高
-   另一个想法，如果满足条件的范围的右端点是当前节点，那么有多少区间是满足条件的呢？
-   设`pre_sum[i]`表示从开始位置到当前位置的前缀和，我们可以从0位置开始，到`i-1`这个范围中，通过`pre_sum[i]`减去前面的前缀和，就得到了一个区间的和

```
如果区间和是从i到j，j是当前需要判断的区间右节点

lower <= pre_sum[j] - pre_sum[i] <= upper

通过上面的不等式，我们发现，可以通过变换得到pre_sum[i]的范围

pre_sum[j] - upper <= pre_sum[i] <= pre_sum[j] - lower

因此，在j之前的前缀和中，如果在[pre_sum[j] - upper, pre_sum[j] - lower]区间范围内的，都是满足条件的
这时候如果前面的前缀和都已经排好序，就能使用二分查找从而找到满足范围的前缀和的数量，也就是以当前节点作为区间右端点满足区间和在[lower,upper]中的区间数量
```

### 代码

```python3
import bisect
from itertools import accumulate


class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        prefix_sorted_sums = [0]

        ans = 0
        for sums in accumulate(nums):
            left = bisect.bisect_left(prefix_sorted_sums, sums - upper)
            right = bisect.bisect_right(prefix_sorted_sums, sums - lower)
            ans += right - left
            bisect.insort(prefix_sorted_sums, sums)
        return ans
```