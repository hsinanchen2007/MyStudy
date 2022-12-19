### 解题思路

使i从0开始遍历到sqrt(c)，若(c - i * i)在开根号后相乘仍等于c，说明i和根号下(c - i * i)平方和为c，返回true

### 代码

```golang
func judgeSquareSum(c int) bool {
	for i := 0;i <= int(math.Sqrt(float64(c)));i++ {
		tmp := c - i * i
		s := math.Sqrt(float64(tmp))
		if int(s) * int(s) == tmp {
			return true
		}
	}
	return false
}
```