### dfs
1. 右节点先遍历

```golang
var res []int

func rightSideView(root *TreeNode) []int {
	res = []int{}
	dfs(root, 1)
	return res
}

func dfs(root *TreeNode, level int) {
	if root == nil {
		return
	}

	if level > len(res) {
		res = append(res, root.Val)
	}

	dfs(root.Right, level+1)
	dfs(root.Left, level+1)
}
```

### bfs
1. 右节点先遍历

```golang
func rightSideView(root *TreeNode) []int {
  
	var res []int
      if root == nil{
        return res
    }
	var queue = []*TreeNode{root}
	var level int
	for 0 < len(queue) {
		length := len(queue)
		for 0 < length {
			length--
			if len(res) == level {
				res = append(res, queue[0].Val)
			}
			if queue[0].Right != nil {
				queue = append(queue, queue[0].Right)
			}
			if queue[0].Left != nil {
				queue = append(queue, queue[0].Left)
			}

			queue = queue[1:]
		}
		level++
	}
	return res
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree)