### 解题思路
此处撰写解题思路

### 代码

```golang
func canConstruct(ransomNote string, magazine string) bool {
	counts := make(map[byte]int)
	lenNote := len(ransomNote)
	for i := 0; i < lenNote; i++ {
		counts[ransomNote[i]]++
	}
	for k, v := range counts {
		if strings.Count(magazine,string(k)) < v {
			return false
		}
	}
	return true
}
```