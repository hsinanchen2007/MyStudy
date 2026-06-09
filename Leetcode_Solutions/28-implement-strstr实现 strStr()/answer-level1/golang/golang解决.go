字串大于主串返回-1，字串等于主串等于1直接比较，字串为空串返回0，如果主串包含字串，则截取主串第一个与字串相等位置+子串长度的切片与字串进行比较，如果相等返回位置，如果不等继续循环，如果相加超过主串数目返回-1：
func strStr(haystack string, needle string) int {
hay := []rune(haystack)
	ned := []rune(needle)
	stackLen := len(hay)
	nedLen := len(ned)
	if nedLen > stackLen {
		return -1
	}
	if nedLen == 1 && stackLen == 1 {
		if hay[0] == ned[0] {
			return 0
		} else {
			return -1
		}

	}
	if needle == "" {
		return 0
	}

	for i := 0; i < stackLen; i++ {
		if hay[i] == ned[0] {
			if i+nedLen > stackLen {
				return -1
			}
			if reflect.DeepEqual(hay[i:i+nedLen], ned[:]) {
				return i
			}
		}
	}
	return -1
}