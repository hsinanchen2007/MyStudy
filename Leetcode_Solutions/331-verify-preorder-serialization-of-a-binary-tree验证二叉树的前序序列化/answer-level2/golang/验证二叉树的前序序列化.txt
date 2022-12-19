### 解题思路
出度和入度的关系

### 代码

```golang
func isValidSerialization(preorder string) bool {
	// 每个非空节点都有两个出度,每个结点都有一个入度(根节点除外), 出度==入度+1
	splits := strings.Split(preorder, ",")
	edge := 1
	for _, str := range splits {
		edge--
        if edge < 0 {
			break
		}
		if str != "#" {
			edge += 2
		}
	}
	return edge == 0

}
```