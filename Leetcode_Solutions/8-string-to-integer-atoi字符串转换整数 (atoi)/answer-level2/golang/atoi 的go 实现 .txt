### 解题思路
此处撰写解题思路

### 思路
1. 把字符串中前面的数字提取处理(前面是指除取头部+-号的)保存在数组中
2. 然后就是处理头部，记录正负号
3. 最后就是累加，数组长度*10^下标*数组值  
4. 每累加一次 要判断是否溢出

### 代码

```golang
func myAtoi(str string) int {
	if str == "" {
		return 0
	} 
	x := 0
	for {
		if x >= len(str) -1 {
			break
		}
		if str[x] == 32 {
			str = str[x+1:]
		} else {
			break
		}
	}

	if str[0] != 45 && str[0] != 43 && isNumChar(str[0]) == 0 {
		return 0
	}
	flag := 0  // 是否负数
	if str[0] == 45 {
		flag = 1
	}
	if str[0] == 43 {
		flag = 0
	}
	// 去除头
	if str[0] == 45 || str[0] == 43 {
		str = str[1:len(str)]
	}
	if str == "" {
		return 0
	} 
	var m []byte
	for i := 0; i < len(str); i++ {
		if isNumChar(str[i]) == 1 {
			m = append(m, str[i] - 48)
		} else {
			break
		}
	}
	ssum := 0
	for j := 0; j < len(m); j++ {
		if m[j] != 0 {
			ssum = ssum + int(m[j]) * mi(10, len(m)-j-1)
			if ssum > mi(2, 31) || ssum < 0  {
				// 溢出
				ssum = mi(2, 31)
				break
			}
		}
	}
	
	if flag == 1 {
		if ssum > mi(2, 31) || ssum < 0  {
			ssum = mi(2, 31)
		}
		ssum = ssum * (-1)
	} else {
		if ssum >= mi(2, 31) || ssum < 0 {
			ssum = mi(2, 31) - 1 
		}
	}
	return ssum

}

func mi(d byte, count int) int {
	sum := 1
	for i := 0; i < count; i++ {
		sum = int(d) * sum
		if sum > 2147483647 || sum < 0  {
			// 溢出
			sum = 2147483648
			break
		}
	}
	return sum
}

func isNumChar(u byte) int{
	if  48 <= u &&  u <= 57 {
		return 1
	} else {
		return 0
	}
}
```