### 解题思路
统计核心

### 代码

```golang
func scoreOfParentheses(S string) int {
	total:= 0
	var depth uint 
	for i := 0; i < len(S); i++ {
		if S[i] == '(' {
			depth++
		} else {
			depth--
			if S[i-1] == '(' {
				total += 1 << depth
			}
		}
	}
	return total
}
```