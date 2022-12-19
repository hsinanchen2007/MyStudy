```go
func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    
    newRoot := &TreeNode{Val:root.Val}
    
    var helper func(*TreeNode, *TreeNode)
    helper = func(tn *TreeNode, ntn *TreeNode) {
        if tn != nil {
            if tn.Right != nil {
                ntn.Left = &TreeNode{Val:tn.Right.Val}   
                helper(tn.Right, ntn.Left)
            }
            
            if tn.Left != nil {
                ntn.Right = &TreeNode{Val:tn.Left.Val}
                helper(tn.Left, ntn.Right)
            }
        }
    }
    
    helper(root, newRoot)
    
    return newRoot
}
```
