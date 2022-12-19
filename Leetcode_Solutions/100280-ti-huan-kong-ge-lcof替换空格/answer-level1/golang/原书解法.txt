### 解题思路
此处撰写解题思路

### 代码

```golang
func replaceSpace(s string) string {
    num_space := 0
	for _, ch := range s {
		if ch == ' ' {
			num_space += 1
		}
	}
	old_len := len(s) - 1
	new_len := old_len + 2*num_space
	// Go语言中字符串是不可变的，首先需要变为切片[],byte代表int8, rune代表int32
	s1 := []rune(s)
	for i := 0; i < 2*num_space; i++ {
		s1 = append(s1, ' ')
	}
	for {
		if old_len < 0 {
			break
		}
		if s1[old_len] == ' ' {
			// 切片赋值通过copy
			copy(s1[new_len-2:new_len+1], []rune{'%', '2', '0'})
			new_len -= 3
		} else {
			s1[new_len] = s1[old_len]
			new_len -= 1
		}
		old_len -= 1
	}
	return string(s1)

}
```