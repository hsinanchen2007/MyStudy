### 解题思路
此处撰写解题思路

我想不到更好的办法，只能简单粗暴的遍历了

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
func countNodes(root *TreeNode) int {
    var res int
    if root == nil {
        return res
    }

    dfs(root, &res)
    return res
}

func dfs(root *TreeNode, res *int) {
    if root == nil {
        return
    }
    
    *res += 1
    dfs(root.Left, res)
    dfs(root.Right, res)
}
```