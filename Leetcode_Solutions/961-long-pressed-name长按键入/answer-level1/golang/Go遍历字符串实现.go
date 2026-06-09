遍历typed字符串，当前字符与name字符不等时，与name字符串的下一位比较，直至name字符串的索引移到最后完成整个串的比较。

```
执行用时 : 0 ms, 在Long Pressed Name的Go提交中击败了100.00% 的用户
内存消耗 : 2.1 MB, 在Long Pressed Name的Go提交中击败了13.64% 的用户
```
```Go []
func isLongPressedName(name string, typed string) bool {
	if name == typed {
		return true
	} else if name == "" || typed == "" {
		return false
	}
	for i, j := 0, 0; i < len(typed) && j < len(name); i++ {
		if name[j] != typed[i] {
			if i == 0 {
				return false
			}
			j++
		} else if j+1 < len(name) && name[j] == name[j+1] {
			j++
		}
		if i == len(typed)-1 && j != len(name)-1 {
			return false
		} else if name[j] != typed[i] {
			return false
		} else if j == len(name)-1 {
			break
		}
	}
	return true
}
