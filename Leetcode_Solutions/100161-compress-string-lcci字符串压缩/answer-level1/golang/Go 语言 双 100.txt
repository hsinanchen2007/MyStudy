### 解题思路
![FireShot Capture 041 - 面试题 01.06. 字符串压缩 - 力扣（LeetCode） - leetcode-cn.com.png](https://pic.leetcode-cn.com/710b0e566dff4857303d7d570676a0a4109ad84533f55e6ad433e209e096c836-FireShot%20Capture%20041%20-%20%E9%9D%A2%E8%AF%95%E9%A2%98%2001.06.%20%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%8E%8B%E7%BC%A9%20-%20%E5%8A%9B%E6%89%A3%EF%BC%88LeetCode%EF%BC%89%20-%20leetcode-cn.com.png)


### 代码

```golang
func compressString(S string) string {
    var str strings.Builder
	strLen := len(S)
	for i := 0; i < strLen; i++ {
		c := S[i]
		iCount := 1
		for ;i < strLen && i+1 < strLen && c == S[i+1]; i++ {
			iCount++
		}
		str.WriteByte(c)
		str.WriteString(strconv.Itoa(iCount))
	}

	if str.Len() >= strLen {
		return S
	}

	return str.String()
}
```