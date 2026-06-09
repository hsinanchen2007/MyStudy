```
//深搜记录层数，数组中添加节点

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

var listNode []*ListNode
func listOfDepth(tree *TreeNode) []*ListNode {
    listNode=make([]*ListNode,0)
	doSomething(tree, 0)
	return listNode
}

func doSomething(tree *TreeNode, n int) {
	ln := &ListNode{tree.Val, nil}
	if len(listNode) <= n {
		listNode = append(listNode, ln)
	} else {
		k := listNode[n]
		for k.Next != nil {
			k = k.Next
		}
		k.Next = ln
	}
	if tree.Left != nil {
		doSomething(tree.Left, n+1)
	}
	if tree.Right != nil {
		doSomething(tree.Right, n+1)
	}
}
```