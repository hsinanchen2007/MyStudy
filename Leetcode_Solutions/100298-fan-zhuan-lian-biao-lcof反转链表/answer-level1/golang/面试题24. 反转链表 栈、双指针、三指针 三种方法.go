### 解题思路
1. 使用栈，栈先进后出的特性使得它来反转轻而易举
2. 使用三个指针
3. 使用俩个指针，其实是将头节点的Next作为第三个指针来用

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    // 使用栈结构作为中介的方法
    if head == nil {
        return nil
    }
    slice := make([]*ListNode, 0)
    for p:=head; p!=nil; p = p.Next {
        slice = append(slice, p)
    }
    for i:=len(slice)-1; i>0; i-- {
        slice[i].Next = slice[i-1]
    }
    slice[0].Next = nil
    return slice[len(slice)-1]
}

func reverseList(head *ListNode) *ListNode {
    // 使用三指针
    if head == nil {
        return head
    }
    if head.Next == nil {
        return head
    }
    pf := head
    pn := head
    pm := head
    pf = head.Next
    pm = head
    pn = nil
    for {
        pm.Next = pn
        if pf == nil {
            return pm
        }
        pn = pm
        pm = pf
        pf = pf.Next
    }
}

func reverseList(head *ListNode) *ListNode {
    // 使用奇怪的双指针
    if head == nil {
        return head
    }
    if head.Next == nil {
        return head
    }
    cur := head.Next
    pre := head
    head.Next = cur.Next
    for {
        if head.Next == nil {
            cur.Next = pre
            return cur
        }
        cur.Next = pre
        pre = cur
        cur = head.Next
        head.Next = cur.Next
    }
    
}
```