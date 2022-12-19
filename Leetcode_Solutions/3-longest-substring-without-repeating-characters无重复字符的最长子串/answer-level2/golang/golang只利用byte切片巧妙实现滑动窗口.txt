总体思路，滑动窗口

```
func lengthOfLongestSubstring(s string) int {
	bytes := []byte(s)
	book := make([]bool, 128)
	var curLen, maxLen int
	// left 滑动窗口左边
	// right 滑动窗口邮编
	for left, right := 0, 0; right < len(s); right++ {

		if !book[bytes[right]] {
			book[bytes[right]] = true
			// 只要没有发现重复，当前子串长度就+1
			curLen++
		} else {
			repetition := bytes[right]
			// 一旦发现子串，立刻结算子串长度
			if curLen > maxLen {
				maxLen = curLen
			}

			for {
				if bytes[left] != repetition {
					// 窗口左侧右移
					book[bytes[left]] = false
					curLen--
					left++
				} else {
					left++
					break
				}
			}
		}
	}
	// 如果该字符串中没有重复的字符，需要全局唯一结算
	if curLen>maxLen{
		maxLen=curLen
	}

	return maxLen

}

```
