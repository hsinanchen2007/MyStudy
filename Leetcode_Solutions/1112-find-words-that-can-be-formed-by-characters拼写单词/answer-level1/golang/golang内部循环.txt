### 解题思路
此处撰写解题思路

### 代码

```golang
func countCharacters(words []string, chars string) int {
	res := 0
	outloop: for _, word := range words {
		for _, i2 := range word{
			if strings.Count(word, string(i2)) > strings.Count(chars, string(i2)) {
				continue outloop
			}
		}
		res += len(word)
	}
	return res
}
```