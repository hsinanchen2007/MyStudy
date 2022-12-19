### 解题思路
此处撰写解题思路

### 代码

```golang

func longestCommonPrefix(strs []string) string {
	rlt := ""
	if strs == nil || len(strs) == 0 {
		return ""
	}
	first := strs[0]
	for i := 0; i < len(first) ; i++ {
		indexRu := string(first[i])
		flagBl := true
		for _, astr := range strs {
			if !(i < len(astr) && string(astr[i]) == indexRu) {
				flagBl = false
				return rlt
			}
		}
		if flagBl == true {
			rlt += indexRu
		}
	}
	return rlt
}

```