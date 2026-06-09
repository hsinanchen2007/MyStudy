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
func levelOrder(root *TreeNode) []int {
    var tree []int
    var t = root
    level := FindHight(t)
    t = root
    for i := 1;i<=level;i++{
        Print(t,&tree,i)
        t = root
    }
    return tree
}
// 输出每层
func Print(root *TreeNode, tree *[]int,level int){
    if root != nil {
        if  level == 1{
            *tree = append(*tree,root.Val)
        }
    }else{
        return
    }
    Print(root.Left,tree,level-1)
    Print(root.Right,tree,level-1)
}
// 获取树高
func FindHight(root *TreeNode) int{
    if root == nil{
        return 0
    }
    l := FindHight(root.Left)
    r := FindHight(root.Right)
    if l > r{
        return l+1
    }else{
        return r+1
    }
}

```