### 解题思路
![image.png](https://pic.leetcode-cn.com/55f5696a156547700184bfac685f6fe00dfd3183b2876146b4c1a7815130ab91-image.png)

- 首先判断和值是否小于等于`target`，如果是，直接返回最大值即可
- 如何才能最接近目标值呢？
- 假设数组中的元素都是一样的，最近接的就是
    - `target//length`
    - `target//length +1`
- 考虑到小于`value`的数不能转化，找出所有小于`target/length`的值，令`target`减去，剩余的数字等分`target`的剩余部分，此时只需要考虑是否整除，不能整除考虑前后两个值的距离绝对值即可




### 代码

```python
import bisect
from itertools import accumulate


class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        total = sum(arr)
        if total <= target:
            return max(arr)
        arr_sort = sorted(arr)
        length = len(arr)
        acc = [0] + list(accumulate(arr_sort))
        pre = 0
        current = bisect.bisect_left(arr_sort, target / length)
        while pre != current:
            pre = current
            current = bisect.bisect_left(arr_sort, (target - acc[current]) / (length - current))

        res1 = (target - acc[current]) // (length - current)
        res2 = res1 + 1
        diff1 = abs(target - acc[current] - res1 * (length - current))
        res2_index = bisect.bisect_left(arr_sort, res2)
        diff2 = abs(target - acc[res2_index] - res2 * (length - res2_index))
        return res1 if diff1 <= diff2 else res2
```