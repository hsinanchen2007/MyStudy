```
func isPalindrome(x int) bool {
    pre := x
    if x < 0 {
        return false
    }
    
    y := 0
    for x != 0 {
        y = y*10 + x%10
        
        x /= 10
    }
    if pre == y {
        return true
    }
    return false
}
```
思路：首先将输入值进行反转，如123反转后为321,然后判断反转前后的值是否相等