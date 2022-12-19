```
func canMeasureWater(x int, y int, z int) bool {
	if x + y < z {
		return false
	}
	return z == 0 || z%gcd(x, y) == 0
}

func gcd(x, y int) int {
	if x < y {
		x, y = y, x
	}
	for y > 0 {
		x, y = y, x%y
	}
	return x
}
```
