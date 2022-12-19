### 解题思路
首先利用滑动窗口计算出和数组 $ss$。然后利用中间的子数组将整个数组分隔，中间子数组的位置范围是从 $k$ 到 $len(ss)-2k$。我们只需要在这个范围内遍历中间子数组，然后在分隔出来的左半部分和右半部分去找左右子数组的最大值就可以了。
遍历的每一步我们都是改变中间部分，并在左部分新加一个，右部分减少一个，因此只需要判断这三个变化，不需要每次都去遍历找最大值。

最终的执行是90%，空间是100%。

### 代码

```python3
import functools
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        N = len(nums)

        ss = [sum(nums[:k])]
        for i in range(k, N) :
            ss.append(ss[-1]+nums[i]-nums[i-k])

        maxl, maxr = ss[0], max(ss[2*k:])
        lp, rp = 0, ss.index(maxr,2*k)
        maxval = maxl + maxr + ss[k]
        res = [lp, k, rp]
        for i in range(k+1, N-2*k+1) :
            changed = False
            if ss[i-k] > maxl :
                changed = True
                maxl, lp = ss[i-k], i-k
            if ss[i+k-1] == maxr :
                changed = True
                maxr = max(ss[i+k:])
                rp = ss.index(maxr,i+k)
            if ss[i] > ss[i-1] or changed:
                sss = maxl + maxr + ss[i]
                if sss > maxval :
                    maxval = sss
                    res = [lp, i, rp]

        return res
```