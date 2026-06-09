```go
func myPow(x float64, n int) float64 {
    if n < 0 {
        if n == -1<<31 {
            return myPow(x, n+1) / x
        }
        x = 1 / x
        n *= -1
    }

    var result float64 = 1
    var current_product float64 = x
    for n > 0 {
        if n&1 == 1 {  // 当前位为1的话就乘上去
            result *= current_product
        }
        // 前进一位
        current_product *= current_product
        n = n >> 1
    }
    return result
}
```