### 解题思路
此处撰写解题思路

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
	if len(s) < 2 {
		return len(s)
	}

	var maxLen = 1
	var slidingWindow []byte = make([]byte, 0)
	var p, q = 0, 1
	slidingWindow = append(slidingWindow, s[0])
	for q < len(s) {
		if len(slidingWindow) > maxLen {
			maxLen = len(slidingWindow)
		}

        for pos, item := range slidingWindow {
            if item == s[q] {
                slidingWindow = slidingWindow[pos+1:]
                break
            } else {
                p++
            }
        }

		slidingWindow = append(slidingWindow, s[q])
		q++
	}
	
	if len(slidingWindow) > maxLen {
		maxLen = len(slidingWindow)
	}

	return maxLen
}
```