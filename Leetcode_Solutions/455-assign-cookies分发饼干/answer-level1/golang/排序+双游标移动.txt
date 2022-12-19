### 解题思路
1. 先排序一下
2. 双游标 i 表示 g 的索引, j 表示 s 的索引，如果 s[j] >= g[i] 那么就给饼干，次数加一，i j 游标都右移，否则仅移动 j 游标
3. 返回次数

### 代码

```golang
func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)

	var count int

	i, j := 0, 0

	for {
		if i >= len(g) {
			break
		}
		if j >= len(s) {
			break
		}

		if s[j] >= g[i] {
			count++
			j++
			i++
		} else {
			j++
		}
	}
	
	return count
}
```