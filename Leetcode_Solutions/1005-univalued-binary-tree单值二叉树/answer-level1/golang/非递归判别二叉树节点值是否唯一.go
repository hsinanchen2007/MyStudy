借用“栈”实现非递归前序遍历二叉树，每次出栈元素值和二叉树根节点值进行比较即可。
```
func isUnivalTree(root *TreeNode) bool {
    if root == nil {
        return true
    }
    
    stack := []*TreeNode{root}
    val := root.Val
    
    for len(stack) > 0 {
        top := stack[len(stack)-1]
        if top.Val != val {
            return false
        }
        stack = stack[:len(stack)-1]
        if top.Right != nil {
            stack = append(stack, top.Right)
        }
        if top.Left != nil {
            stack = append(stack, top.Left)
        }
    }
    
    return true
}
```
