### 解题思路
比较当前节点值与下一节点是否相等，若相等则删除下一节点；若不相等则将指针指向下一节点接着比较。

执行用时 :
0 ms
, 在所有 Go 提交中击败了
100.00%
的用户
内存消耗 :
3.1 MB
, 在所有 Go 提交中击败了
66.06%
的用户

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    var cur *ListNode = head
    for cur != nil && cur.Next != nil {
    // 比较当前节点值与下一节点是否相等，若相等则删除下一节点
        for cur.Next != nil && cur.Val==cur.Next.Val { 
            cur.Next = cur.Next.Next
        }
        cur = cur.Next //若不相等则将指针指向下一节点接着比较
    }
    return head
}
```