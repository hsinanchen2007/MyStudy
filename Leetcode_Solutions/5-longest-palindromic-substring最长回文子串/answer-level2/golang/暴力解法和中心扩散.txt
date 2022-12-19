暴力解法
```
func isPalindrome(s string) bool {

	length := len(s)
	L := 0
	R := length - 1

	sign := true
	for R >= 0 && L <= length-1 && L <= R {

		if s[L] == s[R] {
			//fmt.Println(L, R, string(s[L]), string(s[R]))
			L++
			R--
		} else {
			sign = false
			break
		}
	}

	return sign
}

func longestPalindrome(s string) string {
	length := len(s)

	if length <= 1 {
		return s
	}

	var subStrsArr []string

	var subStr string
	for i := 0; i < length; i++ {
		subStr = string(s[i])
		subStrsArr = append(subStrsArr, subStr)
		for j := i + 1; j < length; j++ {
			subStr += string(s[j])
			subStrsArr = append(subStrsArr, subStr)
		}
	}

	var longestStr string
	for _, subStr := range subStrsArr {
		/*
			newStr := reverseStr(subStr)
			if newStr == subStr && len(longestStr) < len(subStr) {
				longestStr = subStr
			}
		*/
		sign := isPalindrome(subStr)
		if sign == true && (len(subStr) > len(longestStr)) {
			longestStr = subStr
		}
	}

	return longestStr
}
```

中心扩散
```
func longestPalindrome(s string) string {
	length := len(s)

	var longest string
	for i := 0; i < length; i++ {
		L, R := expandAroundCenter(s, length, i, i)
		subStr := s[L+1 : R]

		if len(longest) < len(subStr) {
			longest = subStr
		}

		L, R = expandAroundCenter(s, length, i, i+1)
		subStr = s[L+1 : R]

		if len(longest) < len(subStr) {
			longest = subStr
		}
	}
	return longest
}

func expandAroundCenter(s string, length int, left int, right int) (int, int) {
	var L, R = left, right
	for L >= 0 && R < length && s[L] == s[R] {
		L--
		R++
	}
	//fmt.Println("=================", left, right, "|", L, R, "|", s, s[L+1:R])
	return L, R
}
```

