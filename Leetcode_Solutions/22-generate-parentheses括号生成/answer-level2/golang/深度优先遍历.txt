### 解题思路
深度优先遍历穷举所有可能性，过程中进行条件判断【剪枝】

### 代码

```golang
func generateParenthesis(n int) []string {
	result := make([]string, 0)
	gen("", 0, 0, n, &result)
	return result
}


func gen(current string, left, right, n int, result *[]string) {
	if left == n && right == n {
		*result = append(*result, current)
		return
	}
	if left < n {
		gen(current+"(", left+1, right, n, result)
	}
	if right < n && left > right {
		gen(current+")", left, right+1, n, result)
	}
}


```