### 解题思路
使用map来给字符计数，然后逐个字符串check就行了

### 代码

```golang
func countCharacters(words []string, chars string) int {
	count := 0
	for _, v := range words {
		mc := make(map[byte]int)
		for i := 0; i < len(chars); i++ {
			mc[chars[i]] = mc[chars[i]] + 1
		}
		can := true
		for i := 0; i < len(v); i++ {
			if mc[v[i]] > 0 {
				mc[v[i]]--  
			} else if mc[v[i]] <= 0 {
				can = false
				break
			}
		}
		if can {
			count += len(v)
		}
	}

	return count
}
```