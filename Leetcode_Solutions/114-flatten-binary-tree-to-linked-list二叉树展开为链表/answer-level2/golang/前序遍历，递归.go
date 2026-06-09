### 解题思路
前序遍历，递归的把处理后的左右子树合并
合并条件：
	1. 左子树的叶子节点接上右子树
	2. 左子树移动到右子树的位置
	3. 左子树置空

### 代码

```golang
func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	if root.Right == nil && root.Left == nil {
		return
	}
	if root.Right != nil {
		flatten(root.Right)
	}
	end := root
	if root.Left != nil {
		flatten(root.Left)
		end = end.Left
		for end.Right != nil {
			end = end.Right
		}
	} else {
		return
	}
	end.Right = root.Right
	root.Right = root.Left
	root.Left = nil
}
```