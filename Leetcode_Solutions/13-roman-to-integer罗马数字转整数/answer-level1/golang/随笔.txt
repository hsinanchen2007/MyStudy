### 解题思路
由罗马数字规则可知，从字符串右往左便利时，如果右边的数字比左边的数字大则减去该数字否则相加。
IV
初始化rev = 0，lastNum = 0
第一次循环 subStr = V 对应 5，5 > lastNum(0) 则 rev += 5
此时lastNum = 5
第二次循环 subStr = I 对应 1，1 < lastNum(5) 则 rev = 5 - 1

### 代码

```golang
func romanToInt(s string) int {
	var rev int
	var lastNum int
	for i := len(s) - 1; i >= 0; i-- {
		num := mapping(s[i])
		if lastNum > num {
			rev -= num
		} else {
			rev += num
		}
		lastNum = num
	}

	return rev
}

func mapping(b byte) int {
	var n int
	switch b {
	case 'I':
		n = 1
	case 'V':
		n = 5
	case 'X':
		n = 10
	case 'L':
		n = 50
	case 'C':
		n = 100
	case 'D':
		n = 500
	case 'M':
		n = 1000
	}
	return n
}

```