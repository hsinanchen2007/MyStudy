### 解题思路
此处撰写解题思路

### 代码

```golang
func intToRoman(num int) string {
	table := map[int][]string{
		0: {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		1: {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		2: {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		3: {"", "M", "MM", "MMM"},
	}
	answer := ""
	index := 0
	for num > 0 {
		answer = table[index][num % 10] + answer
		num = num / 10
		index += 1
	}
	return answer
}
```