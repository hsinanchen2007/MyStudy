### 解题思路
层次遍历

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
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func listOfDepth(tree *TreeNode) []*ListNode {
    if tree == nil {
        return nil
    }
    ret := make([]*ListNode,0)
    queue := []*TreeNode{tree}
    for len(queue) > 0 {
        newQ := []*TreeNode{}
        head := &ListNode{}
        cur := head
        for _,treeNode := range queue{
            cur.Next = &ListNode{Val:treeNode.Val}
            cur = cur.Next
            if treeNode.Left != nil {
                newQ = append(newQ,treeNode.Left)
            }

            if treeNode.Right != nil {
                newQ = append(newQ,treeNode.Right)
            }
        }
        ret = append(ret,head.Next)
        queue = newQ
    }
    return ret
}
```