### 解题思路
此处撰写解题思路

### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
	l1 := len(str1)
	l2 := len(str2)
	if l1 <= 0 || l2 <= 0 {
		return ""
	}

	// 如果str1 和str2 有共同能除尽的字符串 那 str1 + str2 == str2 + str1 应该是成立的
	var buffer1,buffer2 bytes.Buffer
	buffer1.Write([]byte(str1))
	buffer1.Write([]byte(str2))
	buffer2.Write([]byte(str2))
	buffer2.Write([]byte(str1))

	if buffer1.String() != buffer2.String() {
		return ""
	}

	n := getGcd(l1,l2)
	return fmt.Sprintf("%s",str1[0:n])
}

// 求最大公约数
func getGcd(n,m int) int {
	for i := n ;i > 1;i-- {
		if n%i == 0 && m%i == 0 {
			return i
		}
	}

	return 1
}
```