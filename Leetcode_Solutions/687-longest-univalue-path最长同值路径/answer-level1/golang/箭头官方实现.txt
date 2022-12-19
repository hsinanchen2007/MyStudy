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
func longestUnivaluePath(root *TreeNode) int {
    ans := 0
    arrowLength(root,&ans)
    return ans
}
//计算箭头长度
func arrowLength(root *TreeNode, ans *int)int{
    if root == nil {
        return 0
    }
    l := arrowLength(root.Left,ans)
    r := arrowLength(root.Right,ans)
    var al, ar int
    if root.Left != nil && root.Left.Val == root.Val {
        al = l +1
    }
    if root.Right != nil && root.Right.Val == root.Val {
        ar = r +1
    }
    *ans = max(*ans,ar+al)
    return max(al,ar)
}
func max(a,b int)int{
    if a >b {
        return a
    }
    return b
}
```