# 解法一 递归
- `中序遍历`
```golang
var res []int

func inorderTraversal(root *TreeNode) []int {
	res = make([]int, 0)
	dfs(root)
	return res
}

func dfs(root *TreeNode) {
	if root != nil {
		dfs(root.Left)
		res = append(res, root.Val)
		dfs(root.Right)
	}
}
```
- ``
# 解法二 迭代（stack）
- 逻辑与 **`解法一 递归`** 一致
- 自建 `stack` 负责 `root` 出栈入栈
```golang
func inorderTraversal(root *TreeNode) []int {
	var res []int
	var stack []*TreeNode

	for root != nil || len(stack) > 0 {
		//push
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}

		//pop
		pre := len(stack) - 1
		res = append(res, stack[pre].Val)
		root = stack[pre].Right
		stack = stack[:pre]
	}
	return res
}
```

# 解法三 Morris 破坏树结构 （`二叉树` 转 `单向升序链表`）
在  **`解法一 递归`**  **`解法二 迭代（stack)`** 中，必须借助 `stack` 来实现 `中序遍历`，增加空间复杂度 `O(n)` 
`Morris` 则在现有节点上进行节点关联，从而避免了 `stack` 空间复杂度 `O(n)` 的问题
- 寻找`左子树` `最大节点` 指向`当前节点`
- 砍掉 `当前节点` 的 `左子树` 

```golang
func inorderTraversal(root *TreeNode) []int {
	var res []int
	var max *TreeNode

	for root != nil {
		if root.Left == nil {
			res = append(res, root.Val)
			root = root.Right
		} else {
			//寻找左树最大节点
			max = root.Left
			for max.Right != nil {
				max = max.Right
			}

			//最大节点指向root
			max.Right = root

			//root = root.Left :移动root到root.left
			//root.Left = nil  :砍左子树，避免下一次遍历到root时，再进入到左子树
			root, root.Left = root.Left, nil
		}
	}
	return res
}
```

# 解法四 Morris 保持树结构
在 **`解法三 Morris 破坏树结构`** 中
- 我们为了避免下一次遍历到`root`时，再进入到`左子树`，直接`砍左子树`

为了解决`砍树`问题，我们可以在 **`解法三 Morris 破坏树结构`** 的基础上，增加
- 在下次遍历到 `root` 时，直接把 `root`加入结果
- 移动到`root.Right` 就可以避免再进入到`左子树`的死循环
```golang
func inorderTraversal(root *TreeNode) []int {
	var res []int
	var max *TreeNode

	for root != nil {
		if root.Left == nil {
			res = append(res, root.Val)
			root = root.Right
		} else {
			max = root.Left
			for max.Right != nil && max.Right != root {
				max = max.Right
			}

			if max.Right == nil {
				// 未连接,连接到root
				max.Right = root
				root = root.Left
			} else {
				// 已连接,断开连接
				max.Right = nil
				res = append(res, root.Val)
				root = root.Right
			}
		}
	}
	return res
}
```

[github](https://github.com/temporaries/leetcode)
