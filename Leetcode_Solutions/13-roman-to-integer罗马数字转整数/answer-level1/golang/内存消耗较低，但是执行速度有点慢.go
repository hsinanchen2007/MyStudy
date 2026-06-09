倒序循环字符串  根据字符对应值依次相加，若遇到当前字符大于上一字符一个等级，正常相加，若小于，则减去当前数值，中间加一个临时变量用于比较
```
func romanToInt(s string) int {
	sMap := map[string]int {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
	var cs = []rune(s)
	var len = len(cs)
	var temp = 0
	var result = 0
	if _, ok := sMap[string(cs[len-1])]; ok {
		temp = sMap[string(cs[len-1])]
		result = sMap[string(cs[len-1])]
	}

	for i:= len-2; i>=0; i-- {
		nowStr := string(cs[i])
		if _, ok := sMap[nowStr]; ok {
			if sMap[nowStr] >= temp {
				result += sMap[nowStr]
			}else {
				result -= sMap[nowStr]
			}
			temp = sMap[nowStr]

		}
	}
	return result
}
```
