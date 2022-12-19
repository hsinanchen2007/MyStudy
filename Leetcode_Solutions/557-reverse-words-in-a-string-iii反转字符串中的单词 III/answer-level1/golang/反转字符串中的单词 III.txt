### 解题思路
so easy

### 代码

```golang

func reverseWord(s string) string {
	var ret []byte
	for i := len(s) - 1; i >= 0; i-- {
		ret = append(ret, s[i])
	}
	return string(ret)
}

func reverseWords(s string) string {
	var temp []string
	ss := strings.Split(s, " ")
	for _ , v := range ss {
		temp = append(temp, reverseWord(v))
	}

	return strings.Join(temp, " ")
}
```