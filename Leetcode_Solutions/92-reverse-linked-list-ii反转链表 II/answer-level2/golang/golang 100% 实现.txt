```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 * 1. 头插法反转链表, 每次将遍历的当前节点插入开始反转的位置。
 * 2. 通过哨兵节点处理 m == 1 的情况
 * 3. 通过m的值确定头插法的头节点位置 
 * 4. 通过n-m的值确定执行几次头插操作
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    dummy,i,j:= &ListNode{Next:head},m,n-m
    d := dummy
    for i > 1{
        d = d.Next
        i--
    }
    cur := d.Next.Next
    pre := d.Next
    for j > 0{
        pre.Next = cur.Next
        cur.Next = d.Next
        d.Next = cur
        cur = pre.Next
        j--
    }
    return dummy.Next
}
```