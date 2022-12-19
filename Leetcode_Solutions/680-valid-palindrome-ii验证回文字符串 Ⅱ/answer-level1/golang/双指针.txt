```
func validPalindrome(s string) bool {

	// 思路，一头一尾，如果当前2个指针指向的元素不相等，则2者其一移动一位后必定相等，否则不能为回文
    // 记录移动即删除字符次数，大于等于2时即不能为回文串
	wrongCount := 0
	lst := strings.Split(s,"")
	i,j := 0,len(lst)-1
    if len(lst) <= 2 {
        return true
	}
	for i <= j {
		if lst[i] == lst[j] {
			if i == j || (i+1) == j {
				return true
			} else {
				i += 1
				j -= 1
				continue
			}
		}
		// 存在左边加一位和右边加一位都相等的情况 即 cuppucu
		if lst[i+1] == lst[j] || lst[i] == lst[j-1] {
			if lst[i+1] == lst[j] && lst[i] == lst[j-1] {
				//对于这种情况，接着比较i+2与j-1 或者 i+1与j-2,即可做出判断
				if lst[i+2] != lst[j-1] {
					j -= 1
                    wrongCount += 1
                    if wrongCount >= 2 {
                        return false
                    }
					continue
				}
			}
			if lst[i+1] == lst[j] {
				wrongCount += 1
				if wrongCount >= 2 {
					return false
				}
				i += 1
				continue
			} else if lst[i] == lst[j-1] {
				wrongCount += 1
				if wrongCount >= 2 {
					return false
				}
				j -= 1
				continue
			}

		} else  {
			return false
		}
	}
	return false
}
```
