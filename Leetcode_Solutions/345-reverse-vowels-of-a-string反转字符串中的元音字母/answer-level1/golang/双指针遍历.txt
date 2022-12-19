### 解题思路
双指针遍历，唯一的区别是指针的移动条件，如果不是元音字符则继续移动。

### 代码

```golang
func reverseVowels(s string) string {
	sr := []rune(s)
	if len(sr) <= 1 {
		return s
	}

	isVowel := func(r rune) bool {
		r = unicode.ToLower(r)
		return r == 'a' || r == 'e' || r == 'i' || r == 'o' || r == 'u'
	}

	low := 0
	high := len(sr) - 1
	for low < high {
		if !isVowel(sr[low]) {
			low++
			continue
		}
		if !isVowel(sr[high]) {
			high--
			continue
		}
		tmp := sr[low]
		sr[low] = sr[high]
		sr[high] = tmp
		high--
		low++
	}
	return string(sr)
}

```