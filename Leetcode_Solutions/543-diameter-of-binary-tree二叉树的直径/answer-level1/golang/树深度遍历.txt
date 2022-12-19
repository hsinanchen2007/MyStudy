### 解题思路
要区分是二叉树还是平衡二叉树，对于完全二叉树很简单，只要对根节点左右子树进行深度求解后相加就行，如果不是完全二叉树，此方法不行
完全二叉树深度求解方法：
func treeDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    left := treeDepth(root.Left)
    right := treeDepth(root.right)

    if left > right {
        return left +1
    } else {
        return right + 1
    }
}
如果非完全二叉树，需要加上判断：
    if *max < left + right {
        *max = left + right
    }

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
func diameterOfBinaryTree(root *TreeNode) int {
    if root == nil {
        return 0
    }
    max := 0
    depth(root, &max)
    return max
}

func depth(root *TreeNode, max *int) int {
    if root == nil {
        return 0
    }

    left := depth(root.Left, max)
    right := depth(root.Right, max)

    if *max < left + right {
        *max = left + right
    }

    if left < right {
        right += 1
        return right
    } else {
        left += 1
        return left
    }
}
```