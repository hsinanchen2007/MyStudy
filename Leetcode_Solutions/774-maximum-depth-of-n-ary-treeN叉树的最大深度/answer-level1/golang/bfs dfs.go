# 算法全是模版，全是套路啊啊啊啊啊啊啊

# bfs
```golang
func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	var queue = []*Node{root}
	var level int
	for 0 < len(queue) {
		length := len(queue)
		for 0 < length {
			length--
			for _, n := range queue[0].Children {
				queue = append(queue, n)
			}
			queue = queue[1:]
		}
		level++
	}
	return level
}
```

# dfs

```golang
var max int

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	var level int
	for _, n := range root.Children {
		level = maxInt(level, maxDepth(n))
	}

	return level + 1
}

func maxInt(a, b int) int {
	if a < b {
		a = b
	}
	return a
}
```

#  
[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree)