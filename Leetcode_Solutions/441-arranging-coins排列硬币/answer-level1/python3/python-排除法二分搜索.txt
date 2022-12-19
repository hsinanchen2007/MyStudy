### 解题思路
二分搜索，排除法。

### 代码

```python3
class Solution:
    def arrangeCoins(self, n: int) -> int:
        # 查找最大的 k 使得 (k+1)*k/2 <= n
        if n == 0:
            return 0
        left, right = 0, n
        while left<right:
            mid =  left + (right-left+1)//2
            if (mid+1)*mid/2 > n:
                right = mid-1   # 这里必须要缩减 right, 而不能缩减 left, 因为是要找最右边的值
            else:
                left = mid
        return left
                
```