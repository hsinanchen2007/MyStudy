### 解题思路
主要考察二分查找，以及退出边界问题

### 代码

```golang
func isPerfectSquare(num int) bool {
    if num == 0 || num == 1 {
        return true
    }
    flag := false
    left, right := 0, num
    for {
        mid := left + (right - left) / 2
        if mid * mid == num {
            flag = true
            break
        } else if num / mid > mid {
            left = mid
        } else {
            right = mid
        }

        if (mid * mid < num && num < (mid + 1) * (mid + 1)) {
            break
        }

    }
    return flag
}
```