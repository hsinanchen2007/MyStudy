### 解题思路

循环判断即可。

### 代码

```golang
func detectCapitalUse(word string) bool {
	if len(word) == 1 {
		return true
	}
	if word[0] < 97 && word[1] < 97 {
		for i := 2;i < len(word);i++ {
			if word[i] >= 97 {
				return false
			}
		}
	}else if word[0] < 97 {
		for i := 1;i < len(word);i++ {
			if word[i] < 97 {
				return false
			}
		}
	}else {
		for i := 1;i < len(word);i++ {
			if word[i] < 97 {
				return false
			}
		}
	}
	return true
}
```