### 解题思路
1、gcd 最大公约数

2、最后调用的数量，只能是最大公约数

### 代码

```golang
package main

//有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
//
//如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
func canMeasureWater(x int, y int, z int) bool {
	if x+y < z {
		return false
	}
	if x == z || y == z || x+y == z {
		return true
	}
	if x == 0 || y == 0 {
		return z == 0 || x+y == z
	}
	return z%Gcd(x, y) == 0
}

func Gcd(x, y int) int {
	if x%y == 0 {
		return y
	} else {
		return Gcd(y, x%y)
	}
}

```