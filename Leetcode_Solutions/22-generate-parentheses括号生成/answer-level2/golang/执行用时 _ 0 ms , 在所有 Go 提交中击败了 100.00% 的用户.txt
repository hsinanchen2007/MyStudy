### 解题思路
此处撰写解题思路

### 代码

```golang
//  dfs
func generateParenthesis(n int) []string {
	var (
		ans = make([]string, 0)
		cur = make([]byte, 0, n*2)
	)

	parenthesisDfs(n, cur, &ans)
	return ans
}

func parenthesisDfs(n int, cur []byte, ans *[]string) {
	if len(cur) == n*2 {
		if isLegalParenthesis(cur) {
            <!-- cur -> string 放在这里做 -->
			*ans = append(*ans, string(cur))
		}
		return
	}

	for _, b := range []byte{'(', ')'} {
		cur = append(cur, b)
		parenthesisDfs(n, cur, ans)
		cur = cur[:len(cur)-1]
	}
}

func isLegalParenthesis(s []byte) bool {
	var level int
	for _, v := range s {
		if level < 0 {
			return false
		}
		if v == '(' {
			level++
		} else {
			level--
		}
	}

	return level == 0
}
```