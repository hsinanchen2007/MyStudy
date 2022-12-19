```
func constructArr(a []int) []int {
	var (
		i      int
		length = len(a)
		rst1   = make([]int, length)
		rst2   = make([]int, length)
	)

	if length == 0 {
		return rst1
	}
	rst1[0] = 1
	rst2[length-1] = 1
	for i = 1; i < length; i++ {
		rst1[i] = rst1[i-1] * a[i-1]
		rst2[length-1-i] = rst2[length-i] * a[length-i]
	}
	for i = 0; i < length; i++ {
		rst1[i] *= rst2[i]
	}

	return rst1
}
```
