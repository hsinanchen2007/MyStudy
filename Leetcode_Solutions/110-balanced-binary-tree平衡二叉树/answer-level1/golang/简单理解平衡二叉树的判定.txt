### 解题思路
面对这个问题，我的想法是分两步处理
1. 深度遍历这棵树，知道每棵子树的深度
2. 判断同一父节点的左右子树的高度差是否大于1，大于则不是平衡二叉树

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
func isBalanced(root *TreeNode) bool {
    
    if root == nil {
        return true
    }

    if int(math.Abs(float64(checkTreeDepth(root.Left)) - float64(checkTreeDepth(root.Right)))) > 1 {
        return false
    }

    if !isBalanced(root.Left) {
        return false
    }

    if !isBalanced(root.Right) {
        return false
    }

    return true
}

func checkTreeDepth(root *TreeNode) int {

    if root == nil {
        return 0
    }

    if root.Left == nil && root.Right == nil {
        return 1
    }

    leftDepth := 0 
    if root.Left != nil {
        leftDepth = checkTreeDepth(root.Left)
    }

    rightDepth := 0
    if root.Right != nil {
        rightDepth = checkTreeDepth(root.Right)
    }

    if leftDepth > rightDepth {
        return leftDepth + 1
    }
    return rightDepth + 1
}
```