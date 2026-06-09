```
func numberOfSteps(num int) (rst int) {
	for num != 0 {
		if num&1 == 0 {
			rst++
			num >>= 1
		} else {
			num -= 1
			rst++
		}
	}
	return rst
}
```
