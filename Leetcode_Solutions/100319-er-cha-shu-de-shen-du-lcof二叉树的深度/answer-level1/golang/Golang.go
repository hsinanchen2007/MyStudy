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
    if root==nil{
        return 0
    }
    max:=0
    var f func(root *TreeNode,deepth int)
    f=func(root *TreeNode,deepth int){
        if root.Left==nil&&root.Right==nil&&deepth>max{
            max=deepth
            return
        }
        if root.Left!=nil{
            f(root.Left,deepth+1)
        }
        if root.Right!=nil{
            f(root.Right,deepth+1)
        }
    }
    f(root,1)
    return max
}
```