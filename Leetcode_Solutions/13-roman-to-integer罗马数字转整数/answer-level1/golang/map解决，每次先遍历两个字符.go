```
func romanToInt(s string) int {
	// 思路：
	// 每次处理当前及下一字符，如果合起来是罗马数字，累加。
	// 如果合起来不是罗马数字，只处理当前一个字符，累加。

	// 定义返回值
	var ret int
	// 定义map, 罗马字符为key，数字为value。
	numRomansMap := map[string]int{
		"M":1000,
		"CM":900,
		"D":500,
		"CD":400,
		"C":100,
		"XC":90,
		"L":50,
		"XL":40,
		"X":10,
		"IX":9,
		"V":5,
		"IV":4,
		"I":1,
	}

	for i := 0; i < len(s); {
		// 因为每次先遍历两个字符（当前字符和下一字符）
		// 所以最后一个字符拿出来单独处理
		if i == len(s)-1 {
			ret += numRomansMap[string(s[i])]
			return ret
		}

		// 判断当前遍历的两个字符是否是 罗马字符
		num,ok := numRomansMap[string(s[i])+string(s[i+1])]
		// 是，进行累加
		if ok && (i+2 == len(s)){
			// 累加的是字符串最后两个字符，返回
			ret += num
			return ret
		}else if ok {
			ret += num
			i += 2
		}else {
			// 否，只处理一个字符
			num := numRomansMap[string(s[i])]
			ret += num
			i++
		}
	}
	return ret
}
```
