**双指针求解**：我们知道，当两个链表长度相等时，指向链表的两个指针是齐头并进的，那么此时很容易找到两链表的交点。那如何处理链表长度不等的情况呢？一种补齐链表长度差的方法就是使用双指针遍历到尾节点后指向另一条链表的头结点，该技巧补齐长度差的证明在此不表。但需要注意的是要处理双指针的相等情况：
双指针相等的情况有两种：
1. 同时到达表尾
2. 同时到达交点

```go
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    if headA == nil || headB == nil {
        return nil
    }
    p1, p2 := headA, headB
    for p1 != p2 {
        if p1 != nil {
            p1 = p1.Next
        } else {
            p1 = headB
        }
        if p2 != nil {
            p2 = p2.Next
        } else {
            p2 = headA
        }
    }
    if p1 != nil {
        return p1
    }
    return nil
}
```