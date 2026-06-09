```
func lengthOfLongestSubstring(s string) int {

	length := len(s)

	if length == 0 || length == 1 {
		return len(s)
	}

	length = length + 1
	content := make([]byte, 0, length)
	content = append(content, 0)

	for i := 0; i < len(s); i++ {
		content = append(content, s[i])
	}

	maps := make([]int, 128)
	left := 1
	right := 1
	maxlen := 0

	for {

		st := maps[content[right]]
        //st为slice中对应的val，如果在slice中已存在
        //1、在窗口的左边框的左方，则st<left，则该值不存在于当前窗口中，窗口可以右扩到此位
        //2、在窗口的左边框的右方，则st>left，则该值在窗口中有重复项，窗口左值变为重复项的右一位，右值右移一位
		if st <left {

			maps[content[right]] = right
			right++

		} else {
			if maxlen < (right - left) {
				maxlen = right - left
                
			}

			left = maps[content[right]]+1

			maps[content[right]] = right
			right++

		}

		if right >= length {
			if maxlen < (right - left) {
				maxlen = right - left
			}
			break
		}
	}
	return maxlen
}
```



