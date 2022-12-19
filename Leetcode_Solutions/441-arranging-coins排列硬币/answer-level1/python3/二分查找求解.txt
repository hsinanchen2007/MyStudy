### 解题思路
先考虑mid(mid+1)/2与n比较的三种情况
然后考虑(mid+1)(mid+2)/2 与n比较的三种情况

### 代码

```python3
class Solution:
    def arrangeCoins(self, n: int) -> int:
        # 二分查找
        low = 0
        high = n
        while low <= high:
            mid = (low + high) // 2
            if mid*(mid+1)/2 == n:
                return mid
            elif mid*(mid+1)/2 > n:
                high = mid - 1
            elif mid*(mid+1)/2 < n:
                if (mid+1)*(mid+2)/2 == n:
                    return mid+1
                elif (mid+1)*(mid+2)/2 > n:
                    return mid
                elif (mid+1)*(mid+2)/2 < n:
                    low = mid + 1
```