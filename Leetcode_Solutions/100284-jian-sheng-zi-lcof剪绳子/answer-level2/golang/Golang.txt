### 解题思路
长度大于3时，最小切分长度是2和3；长度是2或3需要单独讨论。

### 代码

```golang
func cuttingRope(n int) int {
	note := make([]int, n+1)
	var f func(l int) int
	f = func(l int) int {
		if l == 2 {
			return 2
		} else if l == 3 {
			return 3
		} else if note[l] != 0 {
			return note[l]
		} else {
			max := 0
			for i := 2; i <= l/2; i++ {
				tmp := f(i) * f(l-i)
				if max < tmp {
					max = tmp
				}
			}
			note[l] = max
			return max
		}
	}
	if n == 2 {
		return 1
	} else if n == 3 {
		return 2
	}
	return f(n)
}
```