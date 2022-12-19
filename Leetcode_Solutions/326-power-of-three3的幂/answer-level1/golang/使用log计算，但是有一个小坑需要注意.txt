如果是3的幂，那么可以使用log来计算

```go
func isPowerOfThree(n int) bool {
	if n == 0 {
		return false
	}
	if n == 1 {
		return true
	}
	// 换成以10为底的运算
	// log3(n)-> log10(n)/log10(3)
	v := math.Log10(float64(n)) / math.Log10(3)
	// 这里一定要注意即便是n为9，这里计算的结果也是2.0000000000...004
	// 就会计算失败，所以这里要只保留小数点后几位就可以
	v = float64(int(v*100000000000)) / 100000000000
	// 然后将v转换为int并使用原来的v除转换后的数结果为1就为true
	return v/float64(int(v)) == 1
}
```