### 解题思路
升序数组 ，只要我们找出不满足升序条件的数即可

# 中序递归
```golang
var last,first, second *TreeNode

func recoverTree(root *TreeNode) {
	last, first, second = nil, nil, nil
	dfs(root)
	first.Val, second.Val = second.Val, first.Val
}

func dfs(root *TreeNode) {
	if root == nil {
		return
	}
	dfs(root.Left)
	if last != nil && root.Val <= last.Val {
		if first != nil {
			second = root
			return //剪枝
		}
		first, second = last, root
	}
	last = root
	dfs(root.Right)
}
```

# 中序遍历(stack)
```golang
func recoverTree(root *TreeNode) {
	var last, first, second *TreeNode
	var stack []*TreeNode
	for root != nil || len(stack) > 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		pre := len(stack) - 1
		if last != nil && stack[pre].Val <= last.Val {
			if first != nil {
				second = stack[pre]
				break //剪枝
			}
			first, second = last, stack[pre]
		}

		last = stack[pre]
		root = stack[pre].Right
		stack = stack[:pre]
	}
	first.Val, second.Val = second.Val, first.Val
}
```

# Morris
```golang
func recoverTree(root *TreeNode) {
	var last, first, second, max *TreeNode
	for root != nil {
		if root.Left == nil {
			if last != nil && root.Val <= last.Val {
				if first == nil {
					first = last
				}
				second = root
			}
			last = root
			root = root.Right
		} else {
			//寻找左树最大节点
			max = root.Left
			for max.Right != nil && max.Right != root {
				max = max.Right
			}

			if max.Right != root {
				// 未连接,连接到root
				max.Right = root
				root = root.Left
			} else {
				// 已连接，断开连接
				max.Right = nil
				if last != nil && root.Val <= last.Val {
					if first == nil {
						first = last
					}
					second = root
				}
				last = root
				root = root.Right
			}
		}
	}
	first.Val, second.Val = second.Val, first.Val
}
```

[github](https://github.com/temporaries/leetcode)