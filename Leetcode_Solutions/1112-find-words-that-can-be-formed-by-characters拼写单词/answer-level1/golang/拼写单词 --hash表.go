### 解题思路
此处撰写解题思路

### 代码

```golang
func countCharacters(words []string, chars string) int {
	s := make(map[string]int,len(chars))

	for i:=0;i<len(chars);i++ {
		x := string(chars[i])
		s[x]++
	}

	leg := 0
	for _,v := range words {
		ok := true
		m := make(map[string]int)
		for i,v := range s {
			m[i] = v
		}
		for i:=0;i<len(v);i++ {
			if m[string(v[i])] <= 0 {
				ok = false
				break
			}

			m[string(v[i])] --
		}

		if ok {
			leg += len(v)
		}
	}

	return leg
}
```