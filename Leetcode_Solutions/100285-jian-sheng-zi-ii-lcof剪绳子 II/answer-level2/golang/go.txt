祝同学们身体健康！

```
func pow3N(n int) int {
	o := 1
	for i := 0; i < n; i++ {
		o = (o * 3) % 1000000007
	}
	return o
}

func cuttingRope(n int) int {
	if n <= 3 {
		return n - 1
	}
	if m := 2 - n%3; m == 2 {
		return pow3N(n / 3)
	} else {
		return pow3N(n/3-m) * (m + 1) * 2 % 1000000007
	}
}
```