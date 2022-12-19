
一定要抓住规律：
1.除了数字4和9， 其他的数字都是：从左到右，是非递减。例如： 6是 VI， 3是III
2.数字4和9，是 左小右大， IV，IX。

另外：
III值为3，也就是 I + I + I = 3,因此可以把 各个有效的字符代表的数字做累加。
例："LVIII"， L是50，V是5，I是1，I是1，I是1。 最后累加和是58

思路：
1.声明一个初始和为0。
2.从右到左 遍历:
3.判断是否比前面的数大，如果为真，则用s[i]减去 s[i-1] 值为curSum，并且下标往后移动1位。累加和： sum = sum+ curSum; 如果为假， sum = sum + s[i]
```
func romanToInt(s string) int {
	table := map[uint8]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	sum := 0
	for i := len(s) - 1; i >= 0; i-- {
		if i == 0 {
			sum += table[s[i]]
		} else if table[s[i]] > table[s[i-1]] {
			sum += table[s[i]] - table[s[i-1]]
			i--
		} else {
			sum += table[s[i]]
		}
	}
	return sum
}
```

