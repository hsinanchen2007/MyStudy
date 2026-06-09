```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        l, h = 0, sum(nums)
        while l < h:
            mid = (l + h) >> 1
            
            # 贪心试错
            c = 1; r = s = 0
            for i, n in enumerate(nums):
                if s + n > mid:
                    c += 1
                    r = max(r, s)
                    s = n
                else:
                    s += n
            r = max(r, s)
            
            if c <= m and r <= mid:
                h = mid
            else:
                l = mid + 1
        return l
```
- 本题是二分搜索[试错法](https://github.com/cy69855522/Shortest-LeetCode-Python-Solutions/blob/master/README.md#-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE)的又一经典案例，总时间复杂度为 O(Nlog(sum(nums)))
- 我们寻求的答案（最小的子数组各自和最大值）mid 被限制于一个有序的区间 [0, sum(nums)] 之内
- 向左搜索（包括 target）的条件为：nums 可以被划分为不超过 m 个和不超过 mid 的子数组
- 判断条件成立使用了贪心算法：计数 c：nums 可以被划分为至少多少个和不超过 mid 的子数组（注意如果单个数字已经超过 mid 将被单独划分，所以最后需要判断最大子数组和 r 是否满足条件）