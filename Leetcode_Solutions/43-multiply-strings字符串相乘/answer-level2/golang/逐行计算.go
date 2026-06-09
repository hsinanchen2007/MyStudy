### 解题思路
按小学学的乘法，一行一行的计算
这里有个技巧，不用错位（相当于不断乘10），而是用遍历的索引，直接设置错位

### 按行求解

```golang
func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
		return "0"
	}
    
	out := make([]byte, len(num1) + len(num2))
	for i := 0; i < len(num1) + len(num2); i++ {
		out[i] = '0'
	}
	for i := len(num2) - 1; i >=0; i-- {
		for j := len(num1) - 1; j >= 0; j-- {
			sum := out[i + j + 1] - '0' + (num2[i] - '0') * (num1[j] - '0')
			out[i + j + 1] = sum % 10 + '0'
			out[i + j] += sum / 10
		}
	}

	flag := false
	result := make([]byte, 0)
	for i := 0; i < len(num1) + len(num2); i++ {
		if flag == true || out[i] != '0' {
			flag = true
			result = append(result, out[i])
		}
	}

	return string(result)
}

```