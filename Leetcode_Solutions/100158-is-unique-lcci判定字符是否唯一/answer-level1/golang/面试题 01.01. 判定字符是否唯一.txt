### 解题思路
此处撰写解题思路

### 代码

```golang
func isUnique(astr string) bool {

	if len(astr) == 0 {
		return true
	}

	mapS := make(map[string]int)

	for i := 0; i < len(astr); i++ {
		_, ok := mapS[string(astr[i])]
		if ok {
			return false
		} else {
			mapS[string(astr[i])] = mapS[string(astr[i])] + 1
		}
	}
	return true

}
```