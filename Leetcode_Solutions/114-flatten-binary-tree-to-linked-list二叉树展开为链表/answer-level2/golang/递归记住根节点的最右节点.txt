### 解题思路
递归处理每一个节点root，
终止条件为root为空，或者root为叶子节点，

如果左子树不为空，则处理root节点的左子树，并记住该左子树的最右节点leftTreeRightMost，修改root的指针指向该左子树的根节点，同时将左子树的最右节点指向原root节点的右子树。如果原右子树为空，则最右节点仍然是左子树的最右节点。否则，递归处理原右子树

如果左子树为空，则处理root节点右子树root.Right

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func flatten(root *TreeNode) (rightMost *TreeNode) {
    if root == nil || (root.Left == nil && root.Right == nil) {
		return root
	}

    if root.Left != nil {
        leftTreeRightMost := flatten(root.Left)
        right := root.Right
        root.Right = root.Left
        root.Left = nil
        leftTreeRightMost.Right = right
        if right == nil {
            return leftTreeRightMost
        } else {
            return flatten(right)
        }
    }
    
    return flatten(root.Right)
}
```