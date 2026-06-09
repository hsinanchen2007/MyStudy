### 解题思路
golang中对于rune/byte和string的相互转换比较绕，需要小心

### 代码

```golang
func addStrings(num1 string, num2 string) string {
	nr1 := []rune(num1)
	nr2 := []rune(num2)
	result := make([]rune, 0)

	l1 := len(nr1) - 1
	l2 := len(nr2) - 1

	overflow := 0
	for l1 >= 0 || l2 >= 0 {
		v1 := 0
		v2 := 0
		if l1 >= 0 {
			v1 = int(nr1[l1] - '0')
		}
		if l2 >= 0 {
			v2 = int(nr2[l2] - '0')
		}
		value := v1 + v2 + overflow
		overflow = value / 10
		value = value % 10
		result = append([]rune(strconv.Itoa(value)), result...)
		l1--
		l2--
	}
    if overflow > 0{
        result = append([]rune("1"), result...)
    }
	return string(result)
}
```