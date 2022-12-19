```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
    var res []int
    if root == nil {
        return res
    }

    postOrder(root,&res)
    return res
}

func postOrder(t *TreeNode,s *[]int) {
	
	if t.Left != nil {
		postOrder(t.Left,s)
	}

   
	if t.Right != nil {
		postOrder(t.Right,s)
	}

     *s = append(*s,t.Val)

}
```
