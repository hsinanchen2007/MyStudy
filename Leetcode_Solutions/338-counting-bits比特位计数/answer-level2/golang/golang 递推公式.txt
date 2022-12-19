递推，二进制的表示
如果当前为奇数，则在上一个偶数的基础上加一；如果当前为偶数，则和上一个偶数保持一致
```go
func countBits(num int) []int {
    res := make([]int, num+1)
    res[0] = 0
    for i := 1; i <= num; i++ {
        if i & 0x1 == 1 {
            res[i] = res[i-1]+1
        } else {
            res[i] = res[i>>1]
        }
    }
    return res
}
```