思路想通了就很简单，主要是一开始要把900、400等点位也插进去。
```
func IntToRoman(num int) string {
	ret := ""
	if num < 1 || num > 39999 {
		return ret
	}
	values := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	letters := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	for i := 0; i < len(values); {
		if num >= values[i] {
			num -= values[i]
			ret += letters[i]
		} else {
			i++
		}
	}
	return ret

}
```