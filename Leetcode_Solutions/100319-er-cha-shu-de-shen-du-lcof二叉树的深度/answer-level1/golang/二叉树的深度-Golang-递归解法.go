### 解题思路
递归解法：
1、若root为空，树高度为0
2、若root不为空，只有左子树或右子树，那么树的高度为左子树或右子树高度+1
3、若root不为空，有左子树和右子树，那么书的高度为max（左子树高度，右子树高度） + 1

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
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }//endif
    if root.Left == nil && root.Right == nil {
        return 1
    }else if root.Left == nil {
        return maxDepth(root.Right) + 1
    }else if root.Right == nil {
        return maxDepth(root.Left) + 1
    }else {
        leftHigh := maxDepth(root.Left)
        rightHigh := maxDepth(root.Right)
        if leftHigh > rightHigh {
            return leftHigh + 1
        }else {
            return rightHigh + 1
        }//endif
    }//endif
}
```