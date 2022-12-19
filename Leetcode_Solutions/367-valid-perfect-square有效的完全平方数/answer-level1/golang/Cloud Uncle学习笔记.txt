1. 二分法
```
func isPerfectSquare(num int) bool {
    if num <= 0 {
        return false
    }
    
    left, right := 1, num
    for left <= right {
        mid := left + (right - left) / 2
        if mid*mid > num {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    
    return right * right == num
}
```
2. 牛顿迭代法
```
func isPerfectSquare(num int) bool {
    if num <= 0 {
        return false
    }
    
    r := num
    for r*r > num {
        r = (r + num/r)/2
    }
    
    return r * r == num
}
```
