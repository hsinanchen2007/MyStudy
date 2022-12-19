
自从来了力扣我的仿写能力越来越强了....参考 盛夏与微风 的java版写的。
以root为参考点，使用前序遍历比较左右枝叉的值有没和根节点不同的，最后返回true或false

func isUnivalTree(root *TreeNode) bool {
```
 if root == nil{
		return true
	}
    return isTree(root, root.Val) 
}

func isTree (root *TreeNode, val int) bool{
    
	if root == nil {
		return true
        }
    
    if root.Val != val {
        return false
        }    
        return isTree(root.Left, val) && isTree(root.Right, val)
```
｝