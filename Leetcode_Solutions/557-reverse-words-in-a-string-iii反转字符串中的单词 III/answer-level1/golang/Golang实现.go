### 解题思路
- split str转为数组
- 编写一个str反转方法
- range array 调用str反转方法

```
func reverseWords(s string) string {
	data := ""
	split := strings.Split(s, " ")
	end := len(split)-1
	for k,v := range split {
		i := desc(v)
		if k != end {
			data += i + " "
		}else{
			data += i
		}
	}
	return data
}

// str反转方法
func desc(s string) string {
	data := ""
	for i:=len(s)-1;i>=0;i-- {
		data += string(s[i])
	}
	return data
}
```