二分查找，AC了，不知道是不是碰巧，求大佬鉴定
```
class Solution:
    def numOfBurgers(self, m: int, n: int) -> List[int]:
        lo, hi = 0, m//4
        while lo <= hi:
            mid = (lo+hi)//2
            a, b = m - mid*4, n - mid
            if a == b*2:
                return [mid, b]
            elif a > b*2:
                lo = mid+1
            else:
                hi = mid-1
        return []
```
