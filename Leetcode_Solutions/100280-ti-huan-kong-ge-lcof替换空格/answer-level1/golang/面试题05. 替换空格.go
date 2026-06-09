### 解题思路
一顿操作,就行了

### 代码

```golang
func replaceSpace(s string) string {
	// 1.如果为0
	if len(s) == 0 {
		return s
	}
	// 2.计算blank-count的值
	count := 0
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			count++
		}
	}
	// 3.扩充string
	originCount := len(s)
	for i := 0; i < (count*2); i++ {
		s = s + " "
	}
	//4.双指针法
	currCount := len(s)-1
	// 5.golang这个智障语言不支持字符串操作
	str := []rune(s)
	for i := originCount-1; i >= 0; i-- {
	// 6.干就完了	
		if s[i] == ' ' {
			str[currCount] = '0'
			currCount--
			str[currCount] = '2'
			currCount--
			str[currCount] = '%'
			currCount--
		} else {
			str[currCount] = str[i]
			currCount--
		}
	}
	return string(str)
}

```