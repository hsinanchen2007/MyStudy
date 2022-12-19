########
```
func lengthOfLongestSubstring(s string) int {
	if len(s) < 2  {
		return len(s)
	}
	diffCnt := diffCharNum(s)
	if diffCnt <=2 || diffCnt == len(s){
		return diffCnt
	}
	longestCnt := diffCnt
	var subStr string
	for ; longestCnt>=2; longestCnt-- {
		for start:=0; start<=len(s)-diffCnt; start++ {
			// fmt.Println("-------", longestCnt, " ----- start", start)
			subStr = s[start:start+longestCnt]
			if diffCharNum(subStr) == longestCnt {
				// fmt.Println("bingo ", longestCnt, subStr)
				return longestCnt
			}
		}
	}
	return longestCnt
}

func diffCharNum(s string) int  {
	charMapCnt := make(map[uint8]int)
	for i:=0; i<len(s); i++ {
		if _, ex := charMapCnt[s[i]]; !ex {
			charMapCnt[s[i]] = 1
		}else {
			charMapCnt[s[i]]++
		}
	}
	// fmt.Println(len(charMapCnt), "diffs in ", s)
	return len(charMapCnt)
}
```
