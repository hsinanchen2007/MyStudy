### 解题思路
滑动窗口, 计数

### 代码

```golang
func findRepeatedDnaSequences(s string) []string {
	cntMap := make(map[string]int)
	st := 0
	ed := 10
	for ed <= len(s) {
		cntMap[s[st:ed]]++
		st++
		ed++
	}
	res := make([]string, 0)
	for k, v := range cntMap {
		if v > 1 {
			res = append(res, k)
		}
	}
	return res
}
```