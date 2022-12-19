### 解题思路
左边滑动的时候，需要处理3种情况，例如：
1）cca | b
2) cac | b
3) cacc | b

### 代码

```golang
func lengthOfLongestSubstringTwoDistinct(s string) int {
	if len(s) <= 2 {
		return len(s)
	}
	leftIdx, maxLen := 0, 0
	charIdxMap := make(map[uint8]int)

	for i:=0; i<len(s); i++ {
		// fmt.Println(" ---- ", i)
		c := s[i]
		if _, ok := charIdxMap[c]; !ok { //不存在
			if len(charIdxMap) >=2 {  // 达到2个，left需要滑动
				leftCh := s[leftIdx]
				leftIdx = charIdxMap[leftCh]
				if leftIdx < i - 1{
					leftIdx += 1
					delete(charIdxMap, leftCh)
				}else { // leftIdx == i-1
					for k, idx := range charIdxMap {
						if k != leftCh {
							if leftIdx > idx + 1 {
								leftIdx = idx + 1
							}
							delete(charIdxMap, k)
						}
					}
				}
			}
		}

		// update
		charIdxMap[c] = i
		if i-leftIdx+1 > maxLen {
			maxLen = i-leftIdx+1
		}
		// fmt.Println(leftIdx, charIdxMap, s[leftIdx:i+1],maxLen)
	}
	return maxLen
}
```