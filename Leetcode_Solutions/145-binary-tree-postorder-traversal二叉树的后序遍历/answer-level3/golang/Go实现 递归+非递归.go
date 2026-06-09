# **递归**
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
    if root == nil{
        return nil
    }
    
    res := []int{}
    tmp := postorderTraversal(root.Left)
    res = append(res,tmp...)
    tmp2 := postorderTraversal(root.Right)
    res = append(res,tmp2...)
    res = append(res,root.Val)
    return res
}
```

# **非递归实现**
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
    if root == nil{
        return nil
    }
    
    stack,stack2,res := []*TreeNode{},[]*TreeNode{},[]int{}
    stack =append(stack,root)
    for len(stack)!= 0{
        node :=stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        stack2 =append(stack2,node)
        if node.Left != nil{
            stack = append(stack,node.Left)
        }
        
        if node.Right != nil{
            stack = append(stack,node.Right)
        }
       
    }
     for i :=len(stack2)-1;i>=0;i--{
            res = append(res,stack2[i].Val)
        }
    return res
}
```

