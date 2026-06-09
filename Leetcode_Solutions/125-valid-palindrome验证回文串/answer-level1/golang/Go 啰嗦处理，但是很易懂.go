### 解题思路

- 首先预处理字符串，把非字符和数字都去除掉，并把大写字母处理为小写字母
- 随后使用哦双指针，进行左右比较

### 代码

```golang
func prepare(s string) []byte {
	newStr := make([]byte, 0, len(s))
	for i := 0; i < len(s); i++ {
		ch := s[i]
		if ch >= 48 && ch <= 57 {
			newStr = append(newStr, ch)
		}else if ch >= 65 && ch <= 90 {
			newStr = append(newStr, ch+32)
		}else if ch >= 97 && ch <= 122 {
			newStr = append(newStr, ch)
		}
	}
	return newStr
}

func isPalindrome(s string) bool {

	if _len := len(s); _len < 2 {
		return true
	}
	newStr := prepare(s)

	l, r := 0, len(newStr)-1
	for l < r {
		lch := newStr[l]
		rch := newStr[r]
		if lch != rch {
			return false
		}
		l++
		r--
	}
	return true
}
```