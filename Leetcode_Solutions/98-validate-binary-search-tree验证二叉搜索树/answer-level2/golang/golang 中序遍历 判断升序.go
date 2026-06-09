func isValidBST(root *TreeNode) bool {
    var a *int
    val := &a
    return InOrder(root, val)
}

func InOrder(t *TreeNode, val **int) bool {
    if t == nil {return true}
    if ok:= InOrder(t.Left, val); !ok {return false}
    if *val != nil && **val >= t.Val {return false}
    *val = &t.Val
    if ok := InOrder(t.Right, val); !ok {return false}
    return true
}