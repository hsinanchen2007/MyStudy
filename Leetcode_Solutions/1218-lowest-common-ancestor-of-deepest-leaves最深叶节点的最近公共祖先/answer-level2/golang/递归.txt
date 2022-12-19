该题是找最深的叶子节点的最近公共祖先，如果只有一个最深叶子节点就是它本身。
递归查找每一个节点深度，如果两个子节点深度一样，公共节点就是该节点，不等的话，找深度大的子节点，继续往下查找

```
func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	node, _ := recursion(root,0)
	return node
}

func recursion(node *TreeNode, depth int) (*TreeNode, int)  {
	if node == nil {
		return nil, 0
	}
    
	if node.Left == nil && node.Right == nil {
		return node, depth
	}

	//递归两个子节点的深度
	leftNode, leftDepth := recursion(node.Left, depth+1)
	rightNode, rightDepth := recursion(node.Right, depth+1)

	if leftDepth > rightDepth {
		return leftNode, leftDepth
	}else if leftDepth < rightDepth  {
		return  rightNode, rightDepth
	}else {
		return node, rightDepth
	}
}
```
