思路是 整数与罗马数字数字单位从小打到取余数拼接

代码：

``` go

func intToRoman(i int) string {
	if i < 1 || i > 3999 {
		return ""
	}

	if s := romeMap[i]; s != "" {
		return s
	}

	for _, n := range romeBasicNum {
		if n > i {
			continue
		}

		s := romeMap[n]
        // a 为重复次数，b 为余数
		a, b := i/n, i%n

		return repeat(s, a) + intToRoman(b)
	}

	return ""
}

func repeat(s string, n int) string {
	var result string
	for i := 0; i < n; i++ {
		result += s
	}

	return result
}

var romeBasicNum = []int{
	1000,
	900,
	500,
	400,
	100,
	90,
	50,
	40,
	10,
	9,
	5,
	4,
	1,
}

var romeMap = map[int]string{
	1:    "I",
	4:    "IV",
	5:    "V",
	9:    "IX",
	10:   "X",
	40:   "XL",
	50:   "L",
	90:   "XC",
	100:  "C",
	400:  "CD",
	500:  "D",
	900:  "CM",
	1000: "M",
}
```

有优化的地儿 欢迎评论。