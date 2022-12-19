/**
![error.jpg](https://pic.leetcode-cn.com/6157ccd9756bfdd1e1c2a6031f1680f2987b4fce0481a1481438118eb7722bb1-error.jpg)
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var list = []int{}
func inorderTraversal(root *TreeNode) []int {
    if root==nil{
        return []int{}
    }
    if root.Left != nil{
      inorderTraversal(root.Left)
    }
    list = append(list,root.Val)
    if root.Right!=nil{
        inorderTraversal(root.Right)
    }
    return list
}