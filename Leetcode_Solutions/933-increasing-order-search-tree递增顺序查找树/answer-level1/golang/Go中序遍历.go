中序遍历 递归构造新树

```
func increasingBST(root *TreeNode) *TreeNode {
	var tree []int
	tree=serch(root)
	return build(tree,0)
}

func build(n []int,i int) *TreeNode{
	var tree *TreeNode
    tree=new(TreeNode)
	if i<len(n){
    tree.Val=n[i]
    }
    if i<len(n)-1{
	tree.Right=build(n,i+1)
	tree.Left=nil
	}
	return tree
	
}
func serch(root *TreeNode) []int{
	if root==nil{
		return nil
	}
	r1 := serch(root.Left)
    r2 := serch(root.Right)
    return append(append(r1, root.Val), r2...)
}
```


