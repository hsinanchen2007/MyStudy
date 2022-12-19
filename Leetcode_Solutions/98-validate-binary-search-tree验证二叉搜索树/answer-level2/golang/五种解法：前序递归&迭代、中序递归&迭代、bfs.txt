**本题最优解为`中序遍历`**

# 解法一 前序递归

1. 递归方向 `根-左-右`
2. 上下限 `min` `max` 的计算

```golang
func isValidBST(root *TreeNode) bool {
	return dfs(root, -1<<63, 1<<63-1)
}

func dfs(root *TreeNode, min, max int) bool {
	return root == nil || min < root.Val && root.Val < max &&
		dfs(root.Left, min, root.Val) &&
		dfs(root.Right, root.Val, max)
}
```

# 解法二 前序迭代（stack）

1. 与 **`解法一 前序递归`** 逻辑一致， 自建 `stack` 控制 `root` `min` `max` 出栈入栈
```golang
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	var stack = []*TreeNode{root}
	var minS = []int{-1 << 63}
	var maxS = []int{1<<63 - 1}
	for len(stack) > 0 {
		//pop
		pre := len(stack) - 1
		root, min, max := stack[pre], minS[pre], maxS[pre]
		stack, minS, maxS = stack[:pre], minS[:pre], maxS[:pre]

		//push
		for root != nil {
			if root.Val <= min || max <= root.Val {
				return false
			}
			minS = append(minS, root.Val)
			maxS = append(maxS, max)
			stack = append(stack, root.Right)
			max = root.Val
			root = root.Left
		}
	}
	return true
}
```


# 解法三 中序递归

1. 递归方向 `左->根->右`
2. 上一个节点 `last` 赋值时机
3. `last.Val` 必须小于 `root.Val` （因为`中序遍历`=`升序遍历`）


```golang
var last *TreeNode

func isValidBST(root *TreeNode) bool {
	last = &TreeNode{Val: -1 << 63}
	return dfs(root)
}

func dfs(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if !dfs(root.Left) || root.Val <= last.Val {
		return false
	}
	last = root
	return dfs(root.Right)
}
```

# 解法四 中序迭代（stack)
1. 与  **`解法三 中序递归`** 逻辑一致， 自建 `stack` 控制 `root` 出栈入栈

```golang
func isValidBST(root *TreeNode) bool {
	var last = &TreeNode{Val: -1 << 63}
	var stack []*TreeNode
	for root != nil || len(stack) > 0 {
		//push
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}

		//pop
		pre := len(stack) - 1
		if last.Val >= stack[pre].Val {
			return false
		}
		last = stack[pre]
		root = stack[pre].Right
		stack = stack[:pre]
	}
	return true
}
```

# 解法五 bfs（queue）

1. 上下限 `min` `max` 的计算
2. 自建 `queue` 控制 `root` `min` `max` 出列入列

```golang
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	var queue = []*TreeNode{root}
	var minQ = []int{-1 << 63}
	var maxQ = []int{1<<63 - 1}
	for len(queue) > 0 {
		root, min, max := queue[0], minQ[0], maxQ[0]
		if root.Val <= min || max <= root.Val {
			return false
		}
		//push
		if root.Left != nil {
			minQ = append(minQ, min)
			maxQ = append(maxQ, root.Val)
			queue = append(queue, root.Left)
		}
		if root.Right != nil {
			minQ = append(minQ, root.Val)
			maxQ = append(maxQ, max)
			queue = append(queue, root.Right)
		}
		//shift
		queue, minQ, maxQ = queue[1:], minQ[1:], maxQ[1:]
	}

	return true
}
```


[github](https://github.com/temporaries/leetcode)