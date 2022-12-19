```
func isPalindrome(x int) bool {
    _x := x
    tmp := 0 
    for {
        n := _x % 10
        __x := _x / 10
        if _x > 0 {
            tmp = tmp * 10 + n
            _x = __x
        } else {
            break 
        }
    }
    return tmp == x
}
```
