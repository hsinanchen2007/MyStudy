```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var nodes = []int{}

func balanceBST(root *TreeNode) *TreeNode {
    nodes = make([]int,0)
    inorder(root)
    return build(0,len(nodes)-1)
}

func build(start,end int)*TreeNode{
    if start > end{
        return nil
    }
    mid := (start+end)/2
    root := &TreeNode{
        Val: nodes[mid],
    }
    root.Left = build(start,mid-1)
    root.Right = build(mid+1,end)
    return root
}

func inorder(root *TreeNode) {
    if root == nil{
        return
    }
    inorder(root.Left)
    nodes = append(nodes,root.Val)
    inorder(root.Right)
}
```
