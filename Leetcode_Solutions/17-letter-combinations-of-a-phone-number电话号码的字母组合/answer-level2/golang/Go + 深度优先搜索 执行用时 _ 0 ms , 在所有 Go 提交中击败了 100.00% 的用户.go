### 解题思路

经典的深度优先搜索套路

```go
func DFS(){
// 退出条件

	for{
		//做选择
		DFS(next)
		//取消选择
	}
}
```
### 代码

```golang
func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return nil
	}
	m := map[byte][]byte{
		'2': {'a', 'b', 'c'},
		'3': {'d', 'e', 'f'},
		'4': {'g', 'h', 'i'},
		'5': {'j', 'k', 'l'},
		'6': {'m', 'n', 'o'},
		'7': {'p', 'q', 'r', 's'},
		'8': {'t', 'u', 'v'},
		'9': {'w', 'x', 'y', 'z'},
	}
	ds := []byte(digits)
	vector := make([]byte, 0)
	var res []string
	DFS(m, ds, 0, vector, &res)
	return res
}

// index 表示现在取的是哪个数字下的字母，比如2-9
func DFS(m map[byte][]byte, ds []byte, index int, vector []byte, result *[]string) {
	// 终止条件
	if index >= len(ds) {
		*result = append(*result, string(vector))
		return
	}
	b := ds[index]
	for i := 0; i < len(m[b]); i++ {
		// 选择
		vector = append(vector, m[b][i])
		DFS(m, ds, index+1, vector, result)
		// 取消选择
		vector = vector[:len(vector)-1]
	}
}

```