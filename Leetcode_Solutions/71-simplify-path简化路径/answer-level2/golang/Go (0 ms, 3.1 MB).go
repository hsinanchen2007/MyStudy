### 解题思路
获取两个/间的字符串, 判断以下可能：
"..", 出栈
"." 或 "", 不做操作
其他字符串, 入栈
最后将数组用"/"拼接

### 代码

```golang
func simplifyPath(path string) string {
	var arr []string
	// node为两个/间的字符串
	l, node := len(path), ""
	for i := 0; i < l; i++ {
		v := string(path[i])
		if v != "/" {
			node += v
			if i != l-1 {
				continue
			}
		}
		if node == ".." {
			if len(arr) > 0 {
				arr = arr[:len(arr)-1]
			}
		} else if node != "" && node != "." {
			arr = append(arr, node)
		}
		node = ""
	}
	return "/" + strings.Join(arr, "/")
}
```