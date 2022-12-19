# dfs
模板流选手,`前序遍历` 手速一把梭，没啥思路

```golang
var min int

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	min = 1<<63 - 1
	dfs(root, 1)
	return min
}

func dfs(node *TreeNode, depth int) {
	if node.Right == nil && node.Left == nil { //虽然这里没有打印根，但我们停在这里（根）判断了一下，勉强当作前序遍历
		if depth < min {
			min = depth
		}
		return
	}

	if node.Left != nil {
		dfs(node.Left, depth+1)
	}

	if node.Right != nil {
		dfs(node.Right, depth+1)
	}
}
```

# bfs
模板流选手,`广度遍历` 手速一把梭，没啥思路

```golang
func minDepth(root *TreeNode) int {
	var level int
	if root == nil {
		return level
	}
	var queue = []*TreeNode{root}

	for len(queue) > 0 {
		level++
		length := len(queue)
		for 0 < length {
			length--
			if queue[0].Left == nil && queue[0].Right == nil {
				return level
			}
			if queue[0].Left != nil {
				queue = append(queue, queue[0].Left)
			}
			if queue[0].Right != nil {
				queue = append(queue, queue[0].Right)
			}

			queue = queue[1:]
		}
	}
	return level
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree)
[本题完整思路 Github](https://github.com/temporaries/leetcode/tree/master/tree/0111.minimum-depth-of-binary-tree)


