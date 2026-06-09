

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargest(root *TreeNode, k int) int {
	queue := []*TreeNode{}
	res := []int{}
	cur := root
	for cur != nil || len(queue) != 0 {
		if cur != nil{
			queue = append(queue, cur)
			cur = cur.Left
		}else{
			node := queue[len(queue)-1]
			queue = queue[:len(queue)-1]
			res = append(res,node.Val)
			cur = node.Right
		}
	}
	return res[len(res)-k]
}

```