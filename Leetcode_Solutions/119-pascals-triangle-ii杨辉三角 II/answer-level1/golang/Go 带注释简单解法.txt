```
func getRow(rowIndex int) (rst []int) {
	rst = make([]int, rowIndex+1)
	// 方法一：
	// row(n, k) =C(n-1, k-1) = n!/k!/(n-k)!
	// 但是这种方法会溢出
	// 方法二：
	// rst[n] = rst[n-1] + {rst[n-1], 0}
	for i := 0; i <= rowIndex; i++ {
		for j := rowIndex - i; j < rowIndex; j++ {
			rst[j] = rst[j] + rst[j+1]
		}
		rst[rowIndex] = 1
	}
	return
}
```
