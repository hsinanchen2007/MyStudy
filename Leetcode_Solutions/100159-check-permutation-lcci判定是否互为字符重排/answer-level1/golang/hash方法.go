1. 用hash记录下s1每个字符出现的总次数
2. 遍历s2，然后依此递减hash里对应的次数
3. 如果hash里的每个key次数都为0了。说明是可以重排，否则就不行
 
``` go
func CheckPermutation(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	h := make(map[int32]int)
	for _, v := range s1 {
		h[v] = h[v] + 1
	}
	for _, v := range s2 {
		h[v] = h[v] - 1
	}

	for _, v := range h {
		if v != 0 {
			return false
		}
	}
	return true
}
```
