### 解题思路
这道题本可以直接从0循环判断x与i平方的大小关系便能得出，但是会超时，所以用二分法来解决会降低运行时间。

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        half = x // 2
        if x==1 or x==0:
            return x
        l = 1
        r = x // 2
        while l<=r:
            mid = (l+r) // 2
            if x >= mid*mid and x < (mid+1)*(mid+1):
                return mid
            elif x < mid*mid:
                r = mid - 1
            elif x >= (mid+1)*(mid+1):
                l = mid +1


        
        return mid
             
```