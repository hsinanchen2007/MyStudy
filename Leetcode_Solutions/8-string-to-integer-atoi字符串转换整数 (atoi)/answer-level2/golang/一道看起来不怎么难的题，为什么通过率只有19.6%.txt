本题是那种看起来不难，但实际上做起来，呵呵。。。

需要考虑的情况比较多，
1.字符串的空格
2.+ - 号， 这个要保证是字符串中，除空格外第一次出现，才算有效
3.中途出现的无效字符，即第一个数字字符出现之后的所有非数字字符，包括空格 + -号
4.越界的问题！！！ 这个一定要在求值的时候每计算一个字符检查一次，等到最后再判断的话，鬼知道已经到了什么级别
把这些都考虑到了，基本就差不多了，下面是鄙人的提交，O(n) 的算法。  0MS 击败 100%  

```
func myAtoi(str string) int {
	res, flag := 0, 1
	firstNumber := false
	end := false
	for _, s := range str {
		switch s {
		case ' ':
			if firstNumber {
				end = true
				break
			}
			continue
		case '+':
			if firstNumber {
				end = true
				break
			}
			firstNumber = true
			
		case '-':
			if firstNumber {
				end = true
				break
			}
			firstNumber = true
			flag = -1
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			firstNumber = true
			res = res*10 + int((s - '0'))
            if res*flag > math.MaxInt32 {
				return math.MaxInt32
			}
			if res*flag < math.MinInt32 {
				return math.MinInt32
			}
		default:
			end = true
			break
		}
		if end {
			break
		}
	}
	return res * flag
}
```
