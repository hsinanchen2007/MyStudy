解题思路：

由于二叉搜索树是：左子树小于根节点，且根节点小于右子树，


统计左子树的节点个数，假设为N。

1. 若N+1 == K: 则第K小的节点为根节点；

2. 若K > N+1：则第K小的节点在右子树，则在右子树中递归查找第 K-(N+1) 小的值；

3. 若K < N+1：则第K小的节点在左子树，即在左子树中搜索第K小的节点；


```Go
func kthSmallest(root *TreeNode, k int) int {
	if root == nil {
		return 0
	}

	leftNodesCount := countNodes(root.Left)

	// 如果是根节点
	if leftNodesCount+1 == k {
		return root.Val
	}

	// 如果左子树的节点不够k，那么搜索右边的子树
	if leftNodesCount+1 < k {
		return kthSmallest(root.Right, k-leftNodesCount-1)
	}

	return kthSmallest(root.Left, k)
}

// RETURN NODE COUNT
func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}

	// 1 for root
	return 1 + countNodes(root.Left) + countNodes(root.Right)
}
```

运行结果：

- 执行用时 : 12 ms , 在所有 golang 提交中击败了 93.30% 的用户

- 内存消耗 : 5.8 MB , 在所有 golang 提交中击败了 91.46% 的用户


