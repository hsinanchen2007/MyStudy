### 解题思路


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
    //闭包函数dfs共享max变量，max变量记录了访问每个节点的时候的路径长度的最大值
    var max int = 0
    var dfs func (root *TreeNode) int
    dfs = func (root *TreeNode) int {
        if root == nil {
            return 0
        }
        if root.Left == nil && root.Right == nil {
            return 1
        }
        left := dfs(root.Left)
        right := dfs(root.Right)
        //更新路径长度
        max = maxValue(max, left + right)
        return maxValue(left, right) + 1
    }
    dfs(root)
    return max
}

func maxValue(a, b int) int {
    if a >= b {
        return a
    }
    return b
}
```