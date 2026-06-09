遍历二叉树并将节点值存入数组，排序并找到第二小的节点。
```
执行用时 : 0 ms, 在Second Minimum Node In a Binary Tree的Go提交中击败了100.00% 的用户
内存消耗 : 2 MB, 在Second Minimum Node In a Binary Tree的Go提交中击败了37.50% 的用户
```
```Go []
func findSecondMinimumValue(root *TreeNode) int {
	if root == nil || root.Left == nil || root.Right == nil {
		return -1
	}
	vals := []int{root.Val, root.Left.Val, root.Right.Val}
	var getNodeVals func(node *TreeNode)
	getNodeVals = func(node *TreeNode) {
		if node.Left != nil && node.Right != nil {
			vals = append(vals, node.Left.Val)
			vals = append(vals, node.Right.Val)
			getNodeVals(node.Left)
			getNodeVals(node.Right)
		}
	}
	getNodeVals(root.Left)
	getNodeVals(root.Right)
	sort.Ints(vals)
	if vals[0] == vals[len(vals)-1] {
		return -1
	}
	for _, v := range vals {
		if v > vals[0] {
			return v
		}
	}
	return -1
}