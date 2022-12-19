# **递归实现**
```
func inorderTraversal(root *TreeNode) []int {
    if root == nil{
        return nil
    }
    res := []int{}
    tmp1 := inorderTraversal(root.Left)
    res = append(res,tmp1...)
    res = append(res,root.Val)
    tmp2 := inorderTraversal(root.Right)
    res = append(res,tmp2...)
    return res
}
```

# **非递归实现**
```
func inorderTraversal(root *TreeNode) []int {
    if root == nil{
        return nil
    }
    stack,res := []*TreeNode{},[]int{}
    for len(stack) !=0 || root != nil{
        if root != nil{
            stack = append(stack,root)
            root = root.Left
        }else{
            node := stack[len(stack)-1]
            stack = stack[:len(stack)-1]
            res = append(res,node.Val)
            root =node.Right
        }
    }
    return res
}
```

