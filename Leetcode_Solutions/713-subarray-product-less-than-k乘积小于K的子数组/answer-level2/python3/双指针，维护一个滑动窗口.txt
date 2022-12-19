代码较少，效率不错的解法


![图片1.png](https://pic.leetcode-cn.com/1eaf6e57d8610377fd980f2beed2a854c0f15fca916612067dd2bcfcb5770290-%E5%9B%BE%E7%89%871.png)


```
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        start, n, muls, res = 0, len(nums), 1, 0
        for i in range(n):
            muls *= nums[i]
            if muls >= k:               
                while start <= i and muls >= k: #start不要一直往后面跑
                    muls /= nums[start]
                    start += 1
            res += i - start + 1
        return res
```
