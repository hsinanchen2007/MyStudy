思路：
- 特殊情况优先排除，小于 0， 尾数为 0 以及0 到 9 的数都可以提前判断 return
- 取数字的后半段与前半段对比

代码：

```go
func isPalindrome(x int) bool {
    if x < 0 ||(x%10 ==0 && x !=0 ){ // 特殊情况
        return false
    }
    
    if x < 10 { // 特殊情况
        return true
    }
    
    var rNum int
    for x > rNum {
        rNum = rNum * 10 + x%10
        x /= 10
    }
    
    return x == rNum || x == rNum /10 // 第一个判断为 整数长度为偶数时，第二个判断为整数长度为奇数时（奇数时 中间那一位肯定会与自己相等）
}
```