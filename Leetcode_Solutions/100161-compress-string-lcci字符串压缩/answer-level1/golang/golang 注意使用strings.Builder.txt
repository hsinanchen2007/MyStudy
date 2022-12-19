### 解题思路

从这道题里面才认识到
字符串拼接直接使用加号的代价
使用加号进行字符串拼接: 140 ms  8.2 MB
使用strings.Builder进行字符串拼接: 4 ms 3.1MB

### 代码

```golang
func compressString(S string) string {
	var temp byte
	var res strings.Builder
	var count int

	for i := range S {
		if S[i] == temp {
			count++
		}
		if S[i] != temp {
			if temp != 0 {
				res.WriteByte(temp)
				res.WriteString(strconv.Itoa(count))
			}
			temp, count = S[i], 1
		}
	}
	res.WriteByte(temp)
	res.WriteString(strconv.Itoa(count))
	if res.Len() < len(S) {
		return res.String()
	}
	return S
}
```