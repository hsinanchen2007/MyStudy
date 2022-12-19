### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 
func kthSmallest(root *TreeNode, k int) int {
    inorder := []int{}
    stack := []*TreeNode{}
    cur := root
    for (cur != nil || len(stack) > 0){
        for cur != nil{
            stack = append(stack, cur)
            cur = cur.Left
        }
        cur = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        inorder = append(inorder,cur.Val)
        cur = cur.Right
        if len(inorder) == k{
            return inorder[k-1]
        }
    }
    return -1
}

```