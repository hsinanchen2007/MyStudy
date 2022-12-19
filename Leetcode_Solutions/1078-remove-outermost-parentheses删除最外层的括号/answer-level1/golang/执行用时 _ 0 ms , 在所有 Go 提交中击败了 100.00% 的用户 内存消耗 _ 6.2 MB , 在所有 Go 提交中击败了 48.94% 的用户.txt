### 解题思路
此处撰写解题思路

### 代码

```golang
func removeOuterParentheses(S string) string {
	var res string
	cnt := 0
	lp := 0

	for i := 0; i < len(S); i++ {
		if S[i] == '(' {
			cnt++
		} else {
			cnt--
			if cnt == 0 {
				res += S[lp+1 : i]
				lp = i + 1
			}
		}
	}

	return res
}
```