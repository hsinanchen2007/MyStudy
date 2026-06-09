编写递归函数时，必须告诉它何时停止递归。正因为如此，每个递归函数都有两部分：基线条件 （base case）和递归条件 （recursive case）。
递归条件: 函数调用自己
基线条件: 函数不再调用自己，从而避免形成无限循环。

在这里：
基线条件就是：若节点为空，返回深度为0
递归条件：当前节点深度 = 1 + 最大值（左子树，右子数）

```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func maxDepth(root *TreeNode) int {
    if root == nil{
        return 0
    }
    
    count := 1 + Max(maxDepth(root.Left),maxDepth(root.Right))
    return count
    
}

func Max(a, b int) int {
    if a < b {
        return b
    } else {
        return a
    }
}

```

