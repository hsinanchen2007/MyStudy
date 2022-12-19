难点主要是要寻找最大公因子
```
func canMeasureWater(x int, y int, z int) bool { //寻找最大公因子 mx+ny=z
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
