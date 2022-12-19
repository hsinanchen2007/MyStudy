### 解题思路
这是一道数学题。
如果x和y的最大公约数为1的话，那么经过多次迭代之后，可以凑出来[1,x+y]区间的任何正整数。
如果不为1，提取x和y的最大公约数g之后，参照上述可以凑出来[1, (x+y)/g]区间的任何正整数，
但是结果空间为[1, (x+y)/g]的正整数*最大公约数g。

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
  if z == 0 {
    return true
  }
  if x == 0 || y == 0 {
    return z == x || z == y
  }
	var GCD func(x, y int) int
	GCD = func(x, y int) int {
		p1, p2 := x, y
		if p2 > p1 {
			p1, p2 = y, x
		}
		if p1%p2 == 0 {
			return p2
		}
		return GCD(p1%p2, p2)
	}

	g := GCD(x, y)

	return z%g == 0 && z >= 0 && z <= (x+y)
}
```