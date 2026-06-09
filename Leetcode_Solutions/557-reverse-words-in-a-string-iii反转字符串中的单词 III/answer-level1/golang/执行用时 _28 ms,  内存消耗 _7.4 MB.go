### 解题思路  

- 1，先将字符串分解成数组
- 2，使用`for range`循环取出数组中的元素，并执行反转字符串的操作
- 3，将反转后的字符串`append`进一个新的`string`类型的数组
- 4，循环遍历这个新的`string`类型的数组，拼接成一个字符串，返回最终结果

### 代码

```golang
func reverseWords(s string) string {
	ss := strings.Fields(s)
	var results []string
	for _, str := range ss {
		var shift_str []byte
		for i := 0; i < len(str); i++ {
			shift_str = append(shift_str, str[len(str)-i-1])
		}
		results = append(results, string(shift_str))
	}

	re := ""
	for index, value := range results {
		if index == 0 {
			re = re + value
		} else {
			re = re + " " + value
		}
	}

	return re
}
```