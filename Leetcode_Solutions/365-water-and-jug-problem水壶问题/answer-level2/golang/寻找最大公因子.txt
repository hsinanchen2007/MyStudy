### 解题思路
数学问题，寻找最大公因子即可


### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
     if z == 0 {
		return true
	}
	if x+y < z {
		return false
	}
	for y != 0 {
		x, y = y, x%y
	}
	if x != 0 {
		if z%x == 0 {
			return true
		}
	}
	return false
}
```