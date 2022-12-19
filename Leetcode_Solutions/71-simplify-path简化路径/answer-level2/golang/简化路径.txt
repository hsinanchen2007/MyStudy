### 解题思路
栈

### 代码

```golang
func simplifyPath(path string) string {
	stack := make([]string, 0, len(path))
    path = path + "/"
	var dirname strings.Builder
	for _, c := range path {
		switch c {
		case '/':
			str := dirname.String()
			if str == ".." {
				if len(stack) > 0 {
					stack = stack[:len(stack)-1]
				}
			} else if len(str) > 0 && str != "." {
				stack = append(stack, str)
			}
			dirname.Reset()
		default:
			dirname.WriteRune(c)
		}
	}
	dir := strings.Join(stack, "/")
	return "/" + dir
}
```