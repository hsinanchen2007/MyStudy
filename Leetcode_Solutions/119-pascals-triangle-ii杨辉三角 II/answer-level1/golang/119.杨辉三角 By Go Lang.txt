### 解题思路
只需要计算(n+1)/2个即可，以后后半部分重复。
可以参考组合公式计算出元素值
```math
C^(n-1)_(i-1)
```
另外注意乘法越界的事情，就可以了，其实就是及时除以i的阶乘

### 代码

```golang

func factor(n, i int) int {
	if i == 0 {
		return 1
	}
	if i == 1 {
		return n
	}
	s, c := 1, n
	for j := 0; j < i; j++ {
		s *= c
		s /= (j + 1)
		c--
	}
	return s
}

func getRow(rowIndex int) []int {
	n := rowIndex + 1
	if n == 1 {
		return []int{1}
	}
	var buf []int
	for i := 0; i < (n+1)/2; i++ {
		buf = append(buf, factor(n-1, i))
	}
	for i := (n + 1) / 2; i < n; i++ {
		buf = append(buf, buf[n-i-1])
	}
	return buf
}
```