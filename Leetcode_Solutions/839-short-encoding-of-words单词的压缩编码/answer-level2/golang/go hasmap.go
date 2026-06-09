```
//存储后缀
func minimumLengthEncoding(words []string) int {
	tm := make(map[string]int, 0)
	for _, v := range words {
		if _, ok := tm[v]; !ok {
			tm[v] = 1
		}
	}
	fmt.Println(tm)
	for _, v := range words {
		for i := 1; i < len(v); i++ {
			delete(tm, v[i:])
		}
	}
	ans := 0
	for k, _ := range tm {
		ans += len(k) + 1
	}
	return ans
}
```
