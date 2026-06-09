### 解题思路
见代码注释

### 代码

```python
class Solution(object):
    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """
        max_pile = max(piles)

        def ok(piles, i , H):
            times = 0  # 总共需要的时间
            for pile in piles:
                # t = 1 if pile % i > 0 else 0
                times = times + pile // i + (1 if pile % i > 0 else 0)
            return times <= H

        # 暴力求解，超时
        # for i in range(1, max_pile+1):  # i表示一个小时吃多少个
        #     if ok(piles, i ,H):  # i是否满足要求
        #         return i

        # 二分查找之左边界查找
        left = 0  # 数组索引
        right = max_pile  # 搜索区间为[left, right)
        while left < right:
            mid = left + (right - left) // 2  # [left, mid) [mid+1, right)
            if ok(piles, mid+1, H):  # 向左缩小区间，mid+1为mid索引对应的值
                right = mid
            else:
                left = mid + 1

        return left + 1
```