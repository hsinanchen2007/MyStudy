### 解题思路
此处撰写解题思路

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
func sumRootToLeaf(root *TreeNode) int {
    var ans int
    dfs(root,0,&ans)
    return ans
}
func dfs(root *TreeNode,p int,ans *int){
    if root == nil {
        return 
    }
    p = p<<1 +root.Val
    if root.Left == nil && root.Right == nil {
        *ans += p
    }
    dfs(root.Left,p,ans)
    dfs(root.Right,p,ans)
}
```