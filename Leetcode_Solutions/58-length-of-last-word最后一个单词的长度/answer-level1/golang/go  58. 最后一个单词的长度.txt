```
func lengthOfLastWord(str string) int {
	len := len(str)
	if len == 0 {
		return 0
	}
	//不合法的空格位置
	for i := len - 1; i >= 0; i-- {
		if str[i] == ' ' {
			if len == i+1 {
				len = i
				continue
			} else {
				return len - 1 - i
			}
		}
	}

	return len
}
```
