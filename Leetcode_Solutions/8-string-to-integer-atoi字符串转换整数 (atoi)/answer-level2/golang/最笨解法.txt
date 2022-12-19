### 解题思路
此处撰写解题思路
。。。思路是把字符串里（面向测试编程）把数字提取出来放到数组里，再把数组翻转，在每一个去乘以10的次方相加起来，大概没有人会比我更蠢了
### 代码

```golang
func myAtoi(str string) int {
	first := true
	isNegative := false
	isSymbol := false
	var arr []int
	numDict := map[string]int{"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9}
	for i := 0; i < len(str); i++ {
		fmt.Println(111,fmt.Sprintf("%c", str[i]))
		if first && fmt.Sprintf("%c", str[i]) != " " {
			fmt.Println(222,fmt.Sprintf("%c", str[i]))
			if fmt.Sprintf("%c", str[i]) == "+" {
				isSymbol = true
			} else if fmt.Sprintf("%c", str[i]) == "-" {
				isNegative = true
				isSymbol= true
			} else if _, ok := numDict[fmt.Sprintf("%c", str[i])]; ok {
				arr = append(arr, numDict[fmt.Sprintf("%c", str[i])])
			} else {
				return 0
			}
			first = false
		} else {
			fmt.Println(333,fmt.Sprintf("%c", str[i]))
			if _, ok := numDict[fmt.Sprintf("%c", str[i])]; ok {
				arr = append(arr, numDict[fmt.Sprintf("%c", str[i])])
			} else {
				if  _, ok := numDict[fmt.Sprintf("%c", str[i])]; !ok && isSymbol {
					break
				}
				if len(arr) <= 0 {
					continue
				}
				break
				//return 0
			}
		}
	}
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	//coef := 10
	var result float64
	for idx, num := range arr {
		result += float64(num) * powerf(10.0, idx)
	}
	if result > math.MaxInt32 && !isNegative {
		return math.MaxInt32
	}
	if result > math.MaxInt32 && isNegative {
		return math.MinInt32
	}
	if isNegative {
		return int(-result)
	}
	return int(result)
}

func powerf(x float64, n int) float64 {
	ans := 1.0
	for n != 0 {
		ans *= x
		n--
	}
	return ans
}
```