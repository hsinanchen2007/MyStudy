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

import "math"

func isBalanced(root *TreeNode) bool {
    note:=map[*TreeNode]int{}
    var f func(root *TreeNode)int
    f=func(root *TreeNode)int{
        if root==nil{
            return 0
        }else if v,ok:=note[root];ok{
            return v
        }else{
            l:=1+f(root.Left)
            r:=1+f(root.Right)
            if l>r{
                note[root]=l
                return l
            }
            note[root]=r
            return r
        }
    }
    var f2 func(root *TreeNode)bool
    f2=func(root *TreeNode)bool{
        if root==nil{
            return true
        }
        if !f2(root.Left){
            return false
        }
        if !f2(root.Right){
            return false
        }
        if math.Abs(float64(f(root.Left)-f(root.Right)))>1.0{
            return false
        }
        return true
    }
    return f2(root)
}
```