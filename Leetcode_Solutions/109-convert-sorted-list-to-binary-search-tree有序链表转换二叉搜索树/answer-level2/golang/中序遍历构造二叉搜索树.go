### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var cur *ListNode
 // 计算链表长度
func findSize(head *ListNode) int {
    ptr := head
    c := 0
    for nil != ptr {
        ptr = ptr.Next
        c++
    }
    return c
}

func converListToBST(l int, r int) *TreeNode {
    // 递归退出条件
    if l > r {
        return nil
    }

    // 计算下一个顺序值所在位置
    mid := (l + r) / 2

    // 装填左子树
    left := converListToBST(l, mid - 1)
    // 装填当前节点
    root := &TreeNode{
        Val: cur.Val,
        Left: left,
        Right: nil,
    }
    cur = cur.Next
    // 装填右子树
    right := converListToBST(mid + 1, r)
    root.Right = right

    return root
}

func sortedListToBST(head *ListNode) *TreeNode {
    cur = head
    // 调用递归函数完成BST树装填
    size := findSize(head)
    return converListToBST(0, size-1)
}


```