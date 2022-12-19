`xx`， `yy` 需要一次交换
同样 `yy` `xx` 也只需一次
`xy` `yx` 和 `yx` `xy` 需要两次。
所以我们只需要尽可能的用一次交换
```
func minimumSwap(s1 string, s2 string) int {
	x, y := 0, 0
	for i := 0; i < len(s1); i++ {
		if s1[i] == s2[i] {
			continue
		}
		if s1[i] == 'x' {
			x++
		} else {
			y++
		}
	}
	if x%2+y%2 == 1 {
		return -1
	}
	return x/2 + y/2 + 2*(x%2)
}
```
