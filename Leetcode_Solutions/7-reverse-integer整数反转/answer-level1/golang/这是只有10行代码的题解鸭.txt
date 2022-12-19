
```golang []
const maxInt = (1<<31 - 1) / 10
const minInt = (-1 << 31) / 10

func reverse(x int) (ans int) {
	for ; x != 0; x/=10 {
		if ans < minInt || ans > maxInt { return 0 }
		ans = ans * 10 + x % 10
	}
	return
}
```
