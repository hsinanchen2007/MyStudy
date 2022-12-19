```
//
func flatten(root *TreeNode) {
	for root != nil {
		if root.Left == nil {
			root = root.Right
		} else {
			pre := root.Left
			for pre.Right != nil {
				pre = pre.Right
			}
			pre.Right = root.Right
			root.Right = root.Left
			root.Left = nil
			root = root.Right
		}
	}
}
```

```
func flatten(root *TreeNode)  {
    if root==nil{
        return
    }
    var pre *TreeNode
    DFS(root,&pre)
}
func DFS(root *TreeNode,pre **TreeNode){
    if root==nil{
        return
    }
    DFS(root.Right,pre)
    DFS(root.Left,pre)
    root.Right=(*pre)
    root.Left=nil
    (*pre)=root
}
```

