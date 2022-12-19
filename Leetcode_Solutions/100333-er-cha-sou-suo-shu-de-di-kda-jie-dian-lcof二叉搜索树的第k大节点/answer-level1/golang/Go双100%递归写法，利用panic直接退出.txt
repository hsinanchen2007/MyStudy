**就图一乐**
```
func kthLargest(root *TreeNode, k int) (res int) {
    defer func() {
	res = recover().(int)
    }()
    var inOrder func(root *TreeNode) 
    inOrder = func(root *TreeNode) {
	if root == nil {
	    return
	}
	inOrder(root.Right)
	if k == 1 {
	    panic(root.Val)
	}
	k--
	inOrder(root.Left)	
    }
    inOrder(root)
    return
}
```
