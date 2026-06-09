### 解题思路


### 代码

```golang
func nthUglyNumber(n int) int {
	if n == 1 {
		return 1
	}
	nums := make([]int, n)
	nums[0] = 1
	i1, i2, i3 := 0, 0, 0
	for i := 1; i < n; i++ {
		n1 := nums[i1] * 2
		n2 := nums[i2] * 3
		n3 := nums[i3] * 5
		if n1 <= n2 && n1 <= n3 {
			nums[i] = n1
			i1++
		}
		if n2 <= n1 && n2 <= n3 {
			nums[i] = n2
			i2++
		}
		if n3 <= n1 && n3 <= n2 {
			nums[i] = n3
			i3++
		}
	}
	return nums[n-1]
}

```