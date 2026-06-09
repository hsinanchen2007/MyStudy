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
func kthLargest(root *TreeNode, k int) int {
    var f func(root *TreeNode)(int,bool)
    f=func(root *TreeNode)(int,bool){
        if root==nil&&k>1{
            return 0,false
        }
        if root.Right!=nil{
            res,success:=f(root.Right)
            if success{
                return res,true
            }
        }
        if k==1{
            return root.Val,true
        }
        k--
        if root.Left!=nil{
            res,success:=f(root.Left)
            if success{
                return res,true
            }
        }
        return 0,false
    }
    res,_:=f(root)
    return res
}
```