### 解题思路


把false 都写出来就行了

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
func isSameTree(p *TreeNode, q *TreeNode) bool {


    if p == nil && q ==nil{
        return true
    }else if p == nil || q== nil{
        return false
    }else if p.Val != q.Val{
        return false
    }

    return isSameTree(p.Left,q.Left)&& isSameTree(p.Right,q.Right)
}
```