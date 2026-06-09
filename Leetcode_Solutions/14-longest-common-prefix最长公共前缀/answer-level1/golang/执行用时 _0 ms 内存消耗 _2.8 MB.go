### 解题思路
执行用时 :0 ms
内存消耗 :2.8 MB
1.先判断异常情况
2.用第一个字符串跟后面的字符串的每个字符进行比较
时间复杂度O(m*n) m是字符串长度

### 代码

```golang
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	if len(strs) == 1 {
		return strs[0]
	}
	firstStr := strs[0]
	commonPrefix := ""
	var runeArr [][]rune
	//先将每个str转成[]rune，避免在for循环中重复转换
	for _,str := range strs {
		runeArr = append(runeArr,[]rune(str))
	}

	for i,v := range firstStr {
		if !valueEqual(i,v, runeArr) {
			break
		}
		commonPrefix += string(v)
	}
	return commonPrefix
}

func valueEqual(i int, v rune, runeArr [][]rune) bool {
	for j:=1;j<len(runeArr);j++ {
		if len(runeArr[j])-1 < i || v != runeArr[j][i] {
			return false
		}
	}
	return true
}
```