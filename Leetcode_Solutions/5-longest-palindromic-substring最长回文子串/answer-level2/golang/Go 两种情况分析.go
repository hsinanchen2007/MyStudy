从两边向中间不好找，就从中间向两边找

构成回文有两种情况，第一种是下一个和它相同，第二种是前一个和后一个相同，对应不同的端点

确定端点后，开始扩散，直到退出

`func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}
	max := "" // 当前最长回文串
	for i := 0; i < len(s); {
		if i > 0 {
			x := i-1
			y := i+1
			for x >= 0 && y < len(s) && s[x] == s[y] {
				x--
				y++
			}
			temp := s[x+1:y]
			if len(temp) > len(max) {
				max = temp
			}
		}

		x := i
		y := i + 1
		for x >= 0 && y < len(s) && s[x] == s[y] {
			x--
			y++
		}
		temp := s[x+1:y]
		if len(temp) > len(max) {
			max = temp
		}

		i++
	}
	return max
}`