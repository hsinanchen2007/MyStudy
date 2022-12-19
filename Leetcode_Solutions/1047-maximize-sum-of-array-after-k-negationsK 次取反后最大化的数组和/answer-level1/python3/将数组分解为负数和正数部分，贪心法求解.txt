![snap00035.jpg](https://pic.leetcode-cn.com/5219e95a08922378af9d539bb4a5e1c04d77ba31289f15acdbe8ad952d5c0c41-snap00035.jpg)


### 解题思路
将数组A分为负数数组A1 （包括0）,和正数两部分，大小分别为N1和N2个。分两种情况：
1）K小于等于负数数组的大小N1时，则将负数数组由小到大排序，然后依次翻转并按顺序累加（此时最小的负数翻转为最大的正数），直到K用完，然后累加剩余负数；最后累加正数数组；算法复杂度为 O(Nlog(N))，因为有排序。
2）K大于负数数组的大小N1时，先将全部负数翻转（此时全部都是正数了），然后将负数翻转数组和原始正数数组全部累加起来；此时，剩余K-N1次翻转次数，这时候从翻转后的负数数组和最初的正数数组中取最小的数字，反复进行翻转；若K-N1为偶数，则翻转最后数字不影响结果，若为偶数，则需要将累加值减去这个被翻转为负数的数字（减去2次，因为前面多累加了一次）。这种情况下，算法复杂度为 O(N)。

### 代码

```python3
import sys

class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        num_neg = [x for x in A if x <= 0]
        num_pos = [x for x in A if x > 0]
        if K <= len(num_neg):
            num_neg.sort()
            num_max = 0
            for i, num in enumerate(num_neg):
                if i < K:
                    num_max += -num
                else:
                    num_max += num
            for num in num_pos:
                num_max += num
            return num_max
        else:
            N = K - len(num_neg)
            pos_min = 101  # sys.maxsize
            num_max = 0
            for num in num_neg:
                pos_min = min(pos_min, -num)
                num_max += -num
            for num in num_pos:
                pos_min = min(pos_min, num)
                num_max += num

            # print('pos_min', pos_min, 'num_max', num_max)
            if N % 2 == 1:
                num_max -= pos_min*2

            return num_max

```
