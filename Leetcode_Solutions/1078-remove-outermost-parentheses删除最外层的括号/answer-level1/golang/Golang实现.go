解答：使用栈的思想，找到每个原语的起点终点，拼接起点+1 与 终点-1即可。
1.
```
func removeOuterParentheses(S string) string {
	res := ""
	num := 0
	start, end := 0, 0
	flag := false
	for k, v := range S {
		if string(v) == "(" {
			num++
			if !flag {
				start = k
				flag = true
			}
		} else {
			num--
			if num == 0 {
				end = k
				flag = false
				res += S[start+1:end]
				start = end
			}
		}
	}
	return res
}
```
2.
```
func removeOuterParentheses(S string) string {
	res := ""
	num := 0
    index := 0
	for k, v := range S {
		if string(v) == "(" {
			num++
		} else {
			num--
		}
        if num == 1 && string(v) == "(" {
            index = k
        }
        if num == 0 {
            res += S[index+1:k]
        }
	}
	return res
}
```
