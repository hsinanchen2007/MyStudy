### 解题思路
`(a+b)*(a-b) = a*a - b*b`
`a+b = (a*a-b*b) / (a-b)`

### 代码

```golang
func add(a int, b int) int {
	if a == b {
		return 2 * a
	}
	return (a*a - b*b) / (a - b)
}

```