### 解题思路
首先使用map标记每个字符对应的密码，然后对传入的各个word进行解析，放入另一个map中，最后结果即为map长度。

### 代码

```golang
func uniqueMorseRepresentations(words []string) int {
	seed := []string {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}
	md := make(map[rune]string)
	var n rune = 97
	for _, v := range seed {
		md[n] = v
		n++
	}

	mw := make(map[string]int8)
	for _, word := range words {
		temp := ""
		for _, char := range word {
			temp += md[char]
		}
		mw[temp] = 1
	}
	return len(mw)
}
```