```golang
func convertToTitle(n int) string {
    if n <= 26 {
        return string(64 + n)
    }    
    y := n % 26
    if y == 0 { // 特殊情况
        return convertToTitle((n - y - 1) / 26) + convertToTitle(26)
    }
    return convertToTitle((n - y) / 26) + convertToTitle(y)
}
```