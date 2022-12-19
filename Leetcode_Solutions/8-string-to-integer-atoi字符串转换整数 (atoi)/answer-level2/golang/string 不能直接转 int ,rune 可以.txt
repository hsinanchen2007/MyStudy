### 解题思路
菜鸡只配抄。。。

### 代码

```golang
func myAtoi(str string) int {
	res, flag := 0, 1  //结果,正负标记
	firstNumber := false  //只有第一个字符符合条件才会往后遍历，并且如果后面出现了不符合条件的字符，可以置false终止循环
	end := false
	for _, s := range str {
		switch s {
		case ' ':          //匹配空字符，如果是排在前面的空字符，继续，如果已经出现过正负号或者数字，就退出
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
			res = res*10 + int((s - '0')) //双引号是字符串，单引号是 rune 类型，string 不能直接转 int ，但是 rune 可以
            if res*flag > math.MaxInt32 {// 判断溢出
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