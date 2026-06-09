### 解题思路
此处撰写解题思路

### 代码

```golang
func compressString(S string) string {
	n := len(S)
	if n <= 1 {
		return S
	}

	str := ""
	count := 1
	for i:= 1;i<n;i++ {

		if S[i] == S[i-1] {
			count ++
		}else {
			str += string(S[i-1]) + strconv.Itoa(count)
			count = 1
		}

		if i >= n-1 {
			str = str + string(S[i]) + strconv.Itoa(count)
			break
		}
	}

	if len(str) >= len(S) {
		return S
	}

	return str
}
```