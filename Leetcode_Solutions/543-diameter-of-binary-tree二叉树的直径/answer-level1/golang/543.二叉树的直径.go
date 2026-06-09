### 解题思路

二叉树直径就是路径经过节点的最大值-1.递归求出路径经过节点的最大值，减去1就是直径。

### 代码

```golang
var res int
func diameterOfBinaryTree(root *TreeNode) int {
	res = 1
	depth(root)
	return res - 1
}
func depth(node *TreeNode) int {
	if node == nil {
		return 0
	}
	l := depth(node.Left)
	r := depth(node.Right)
	if res < l + r + 1 {
		res = l + r + 1
	}
	if l > r {
		return l + 1
	}else {
		return r + 1
	}
}
```