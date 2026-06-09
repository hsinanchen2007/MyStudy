首先将 to_delete转换成map，方便判断。

判断root
1. 如果root为null直接返回
2. 如果root.Val在删除列表中，那么后面的子节点已经和这个主节点没有任何关系了，直接以left和right单独作为树的根进行计算
3. 如果root.Val不在删除列表，那么下面的子树可能还会保留在当前树中，继续往下计算即可
```
func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
    m := make(map[int]bool)
    for i := 0; i < len(to_delete); i++ {
        m[to_delete[i]] = true
    }
    return delNode(root, m)
}

func delNode(root *TreeNode, m map[int]bool) []*TreeNode {
    root, ret := del(root, m)
    if root == nil {
        return ret
    }
    return append(ret, root)
}

func del(root *TreeNode, m map[int]bool) (*TreeNode, []*TreeNode) {
    ret := []*TreeNode{}
    if root == nil {
        return nil, nil
    }
    if m[root.Val] {
        return nil, append(delNode(root.Left, m), delNode(root.Right, m)...)
    }
    left, l := del(root.Left, m)
    root.Left = left
    ret = append(ret, l...)
    
    right, r := del(root.Right, m)
    root.Right = right
    ret = append(ret, r...)
    
    return root, ret
}
```
