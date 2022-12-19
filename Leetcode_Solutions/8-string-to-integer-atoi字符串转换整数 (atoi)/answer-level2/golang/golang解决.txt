golang 解法
github: https://github.com/Crownt/leetcode

```
// 时间复杂度：O(m),为有效数字的长度  空间复杂度：O(n)，数组strArr所占 

func myAtoi(str string) int {

	str = strings.TrimLeft(str, " ")
	if len(str)==0 {
		return 0
	}

	strArr := []rune(str)
	start := 0  // 数组起始位
	flag := 1  // 符号标示，'1'表示'+', '0'表示'-'
	if strArr[0]<'0' || strArr[0]>'9' {
		if strArr[0]=='+' {
			start = 1
		}else if strArr[0]=='-' {
			start = 1
			flag = 0
		}else {
			return 0
		}
	}

	res := 0
	for i:=start; i<len(str); i++ {

		// 遇到第一个非数字字符，则返回结果
		if strArr[i]<'0' || strArr[i]>'9' {
			if flag==0 {
				res = -res
			}
			return res
		}

		// 正向溢出预先判断
		if flag==1 {
			if res>math.MaxInt32/10 || (res==math.MaxInt32/10 && strArr[i]-'0'>7){
				return math.MaxInt32
			}
		}

		// 负向溢出预先判断
		if flag==0 {
			if (-1)*res<math.MinInt32/10 || ((-1)*res==math.MinInt32/10 && strArr[i]-'0'>8) {
				return math.MinInt32
			}
		}
		
		res = res * 10 + int(strArr[i]-'0')
	}

	if flag==0 {
		res = -res
	}

	return res
}
```
