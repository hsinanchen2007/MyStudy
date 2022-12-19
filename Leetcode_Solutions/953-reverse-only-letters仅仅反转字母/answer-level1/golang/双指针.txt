### 解题思路
依然是双指针

### 代码

```golang
func reverseOnlyLetters(S string) string {
   msgs := []rune(S)
	for i, j := 0, len(msgs) - 1; i < j ;  {
		if unicode.IsLetter(msgs[i]) && unicode.IsLetter(msgs[j]){
			msgs[i], msgs[j] = msgs[j], msgs[i]
			i, j = i+1, j -1
		}else if unicode.IsLetter(msgs[i]) && !unicode.IsLetter(msgs[j]){
			j--
		}else if !unicode.IsLetter(msgs[i]) && unicode.IsLetter(msgs[j]){
			i++
		} else {
			i, j = i+1, j -1
		}
	}

	return string(msgs)
}

```