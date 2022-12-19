```
func pruneTree(root *TreeNode) *TreeNode {
    postPrune(&root)
    
    return root
}
// 后序遍历进行符合条件的节点删除
func postPrune(node **TreeNode) {
    if node == nil {
        return 
    }
    if (*node).Left != nil {     
        postPrune(&(*node).Left)
    }
    if (*node).Right != nil {
        postPrune(&(*node).Right)
    }
    // 如果满足它的左右孩子都为nil，且本身val为0，则将该二级指针指向nil（解引用）
    if (*node).Val == 0 && (*node).Right == nil && (*node).Left == nil {
        *node = nil
    }
}
```
