### 解题思路
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.6 MB, 在所有 Go 提交中击败了93.75%的用户

第一次做题，在左边收缩的时候，缩到了窗内满足替换K个的要求，看了题解，其实小于最大长度的滑窗是不用考虑的，多余的。

### 代码

----------------- 第二次 ----------------------------------------
```golang
func characterReplacement(s string, k int) int {
	if k < 0 {
		k = 0
	}
	if len(s)+1 <= k {
		return len(s)
	}
	chCnt := make([]int, 26)
	maxLen, maxChCnt, leftIdx := 0, 0, 0

	for i:=0; i<len(s); i++ {
		chCnt[s[i]-'A']++
		if chCnt[s[i]-'A'] > maxChCnt {
			maxChCnt = chCnt[s[i]-'A']
		}

		if i-leftIdx+1-maxChCnt > k {
			ch := s[leftIdx]
			chCnt[ch-'A']--
			leftIdx++
		}

		if i-leftIdx+1 > maxLen {
			maxLen = i-leftIdx+1
		}
	}
	return maxLen
}
```

----------------- 第一次 ----------------------------------------
```golang
var maxCh uint8
var chCntMap map[uint8]int
var maxChCnt int
var leftIdx int

func characterReplacement(s string, k int) int {
	if k < 0 {
		k = 0
	}
	if len(s) <= k {
		return len(s)
	}

	chCntMap = make(map[uint8]int)
	maxCh = 0
	maxChCnt = 0
    maxLen := 0
    leftIdx = 0

    for i:=0; i<len(s); i++ {
    	 // fmt.Println(i, s[i:i+1], "------")
    	 c := s[i]
    	 if _, ok := chCntMap[c]; ok {
			 chCntMap[c] += 1
		 }else {
		 	 chCntMap[c] = 1
		 }
		 // update
		 if chCntMap[c] > maxChCnt {
		 	maxChCnt = chCntMap[c]
		 	maxCh = c
		 }
		 othersCnt := i - leftIdx + 1 - maxChCnt
		 if othersCnt > k {
			 moveR(i, s, k)
		 }

		 if i - leftIdx + 1 > maxLen {
		 	maxLen = i - leftIdx + 1
		 }
		 // fmt.Println(leftIdx, s[leftIdx:i+1], maxLen)
	}

	return maxLen
}

func moveR(cur int, s string, k int)  {
	for {
		if leftIdx >= cur {
			break
		}
		othersCnt := cur - leftIdx + 1 - maxChCnt
		if othersCnt <= k  {
			break
		}
		leftCh := s[leftIdx]
		chCntMap[leftCh] -= 1
		leftIdx += 1
		if leftCh != maxCh {
			break
		}else {
			maxChCnt--
			// update MaxCh
			for c, cnt := range chCntMap {
				if cnt > maxChCnt {
					maxChCnt = cnt
					maxCh = c
				}
			}
		}
	}
}
```