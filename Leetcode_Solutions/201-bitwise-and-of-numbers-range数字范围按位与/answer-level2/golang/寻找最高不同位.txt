```
// Ref: https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/0he-shui-yu-du-shi-0-by-powcai/
func rangeBitwiseAnd(m int, n int) int {
	var (
		i = 0
	)

	// m == n 意味着找到了二进制中不同的最后位为第 i 位
	for m != n {
		m >>= 1
		n >>= 1
		i++
	}
	return m << i
}
```
