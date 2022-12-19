python版本二分查找：
```
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num <= 4:
            return num == 1 or num == 4
        l, r = 0, num
        while l < r:
            mid = (l+r) // 2
            tmp = mid * mid
            if tmp == num:
                return True
            elif tmp < num:
                l = mid + 1
            else:
                r = mid
        return False
```
go版本二分查找：
```
func isPerfectSquare(num int) bool {
    if num <= 4 {
        return num == 1 || num == 4
    }
    l, r := 0, num
    for l < r {
        mid := (l+r) / 2
        tmp := mid * mid
        if tmp == num {
            return true
        } else if tmp < num {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return false
}
```
