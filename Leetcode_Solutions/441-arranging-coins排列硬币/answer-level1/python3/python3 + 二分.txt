### 解题思路
二分查找就行了，使用等差数列优化求和，不然会超时.

### 代码

```python3
class Solution:
    def arrangeCoins(self, n: int) -> int:
        # 使用等差数列求和公式优化
        def coins(counter):
            # 1 + 2 + 3 +... + n = n(1 + n)/2
            sums = counter * (1 + counter) / 2
            return sums

        left = 0
        right = n
        while left < right:
            # 定义行 为mid
            mid = left + ((right - left + 1) >> 1)
            # 判断当前行，构建，硬币是否足够
            if coins(mid) > n:
                right = mid - 1
            else:
                left = mid
        return left
```