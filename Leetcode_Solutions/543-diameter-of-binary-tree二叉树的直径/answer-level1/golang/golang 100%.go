### 解题思路
递归方法。此题的核心就是遍历每个节点，计算出其左右子树的深度之和中的最大值。（注意由于leetcode的问题，在调用函数时，需要初始化一次全局变量，避免在执行代码时没问题，却在提交代码时报错的bug）

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
var max int = 1
func diameterOfBinaryTree(root *TreeNode) int {
    max = 1
    depth(root)
    return max-1
}

func depth(node *TreeNode) int {
    if node == nil {
        return 0
    }
    
    l := depth(node.Left)
    r := depth(node.Right)
    x := l+r+1
    if x > max {
        max = x
    }
    if l > r {
        return l+1
    } else {
        return r+1
    }
}
```