### 解题思路
遍历链表，注意处理进位，和退出条件
![Screen Shot 2020-03-15 at 1.10.06 AM.png](https://pic.leetcode-cn.com/2fb2a356b7b10c64e58bb0885508678745a775ead62ce4e3657bdce41fd87769-Screen%20Shot%202020-03-15%20at%201.10.06%20AM.png)



### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }
    head := l1
    cur := head
    p1, p2 := l1, l2
    jw := 0
    for p1 != nil && p2 != nil {
        cur = p1
        cur.Val = p1.Val + p2.Val + jw
        jw = cur.Val / 10
        cur.Val = cur.Val % 10
        p1 = p1.Next
        p2 = p2.Next
    }
    if p2 != nil {
        cur.Next = p2
    }

    for cur.Next != nil {
        if jw == 0 {
            return head
        }
        next := cur.Next
        next.Val = jw + next.Val
        jw = next.Val / 10
        next.Val = next.Val % 10
        cur = next
    }
    if jw == 0 {
        return head
    }
    node := new(ListNode)
    node.Val = jw
    node.Next = nil
    cur.Next = node
    
    return head
}
```