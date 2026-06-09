1. 如果小于root，则插入root的右树（insertRight），如果大于root，则选取该点为新root，将原树变为新root的左树（reRoot）
2. insertRight: 对于路径上的节点，如果遇到小于该值的节点，则用该值取代原节点，并将该节点的子树赋值给新节点的左树
3. reRoot: 修改根为新节点，将原树赋值给新节点的左孩子

```
func insertIntoMaxTree(root *TreeNode, val int) *TreeNode {
    // 插入右子树
    if val < root.Val {
        insertRight(val, root)
        return root
    } 
    
    return reRoot(val, root)
}

func insertRight(val int, root *TreeNode) {
    cursor := root
    for {
        if cursor.Right != nil {
            if cursor.Right.Val < val {
                cursor.Right = reRoot(val, cursor.Right)
                return
            } 
            cursor = cursor.Right
        } else {
            break
        }
    }
    
    cursor.Right = newNode(val)
    return
}

// 修改根为新节点
func reRoot(val int, root *TreeNode) (newRoot *TreeNode) {
    newRoot = newNode(val)
    newRoot.Left = root
    return
}

func newNode(val int) *TreeNode{
    return &TreeNode {
        Val: val,
        Left: nil,
        Right: nil,
    }
}
```