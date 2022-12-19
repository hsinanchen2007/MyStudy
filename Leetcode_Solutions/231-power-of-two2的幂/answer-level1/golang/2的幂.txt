只需要统计二进制下1的个数即可，当且仅当1的个数只有1个时，才是2的幂，Go语言实现，用时0毫秒

``` go
func isPowerOfTwo(n int) bool {
    var cnt = 0
	for n > 0 {
		if n&1 == 1 {
			if cnt == 1 {
				return false
			}
			cnt++
		}
		n >>= 1
	}
	return cnt == 1
}
```