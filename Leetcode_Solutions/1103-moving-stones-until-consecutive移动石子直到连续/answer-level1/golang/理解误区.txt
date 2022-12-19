我们在理解的时候可能有一个误区. 那就是 a,b,c 和 x,y,z  并不是固定的. x<y<z 但 a,b,c 的大小是不一定的.
所以,我们理解成 a,b,c 中 最小的一定是x , 最大的一定是 z . 即我们可以对a,b,c 进行排序. 排好序后再进行‘位置’差距的计算 
而不是直接计算.

```
func numMovesStones(a int, b int, c int) []int {

	if a < b {
		a, b = b, a
	}
	if b < c {
		b, c = c, b
	}
	if a < b {
		a, b = b, a
	}

	if a-b == 1 && b-c == 1 {
		return []int{0, a - c - 2}
	}
	if a-b <= 2 || b-c <= 2 {
		return []int{1, a - c - 2}
	}

	return []int{2, a - c - 2}
}
```
