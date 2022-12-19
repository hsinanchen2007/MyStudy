### 解题思路

### 代码

```golang
func isPalindrome(x int) bool {
    var str = strconv.Itoa(x)
    if x < 0 {
        return false
    }
    for i := range str{
        if str[len(str)-1-i] != str[i] {
            return false
        }
    }
    return true
}
```