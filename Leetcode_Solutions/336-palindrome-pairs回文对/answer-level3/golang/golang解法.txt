```

func palindromePairs(words []string) [][]int {
	var ret [][]int
	lenWords := len(words)
	for i := 0; i < lenWords; i++ {
		for j := 0; j < lenWords; j++ {
			if i == j {
				continue
			}
			if len(words[i]) == len(words[j]) {
				if isReverse(words[i], words[j]) {
                    tmp := []int{i, j}
					ret = append(ret, tmp)
				}
			} else {
				if isTwoUnEqualReverse(words[i], words[j]) {
					tmp := []int{i, j}
					ret = append(ret, tmp)
				}
			}
		}
	}
	return ret
}

func isTwoUnEqualReverse(a string, b string) bool {
	lenA := len(a)
	lenB := len(b)
	if lenA > lenB {
		if !isReverse(a[0:lenB], b) {
			return false
		}
		len1 := lenA - lenB
		len2 := len1 / 2
		len3 := len2
		if len1%2 != 0 {
			len3 = len2 + 1
		}
		if !isReverse(a[lenB:lenB+len3], a[lenB+len2:lenA]) {
			return false
		}
	}
	if lenA < lenB {
		if !isReverse(a, b[lenB-lenA:lenB]) {
			return false
		}
		len1 := lenB - lenA
		len2 := len1 / 2
		len3 := len2
		if len1 % 2 != 0 {
			len3 = len2 + 1
		}
		if !isReverse(b[0:len3], b[len2:lenB]) {
			return false
		}
	}
	return true
}

func isReverse(a string, b string) bool {
	lenA := len(a)
	for k := 0; k < lenA; k++ {
		if a[k] != b[lenA-k-1] {
			return false
		}
	}
	return true
}

```
