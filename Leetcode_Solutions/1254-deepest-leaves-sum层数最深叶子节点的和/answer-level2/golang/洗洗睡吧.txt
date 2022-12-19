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
var deep , res int
func deepestLeavesSum(root *TreeNode) int {
    deep,res=0,0
    getResult(root,1)
    return res
}


func getResult(root *TreeNode,num int){
    if root==nil{
        return
    }
    if num==deep{
        res+=(*root).Val
    }else if num>deep {
        deep=num
        res=(*root).Val
    }
    getResult((*root).Left,num+1)
    getResult(root.Right,num+1)

}
```