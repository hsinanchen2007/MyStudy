
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
```


```
 // 这个逻辑我自己都看不懂了
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    dummy := &ListNode{Next:head}
    slow,fast := dummy,head
    // 该数值必须与所有测试案例中的第一个结点值相异,但是测试案例貌似并不全是升序的，有个 【2，1】的测试数据
    temp := head.Val - 10 
    for  fast.Next != nil {
        if temp != fast.Val {
            if fast.Next.Val == fast.Val {
                temp = fast.Next.Val
            } else {
                slow.Next = fast
                slow = slow.Next
                fast = fast.Next
                continue
            }     
        }
        fast = fast.Next
    }
    // 判断存储的temp值是否和当前fast的相同，不同则将节点添加
    if temp == fast.Val {
        fast = nil
    }
    slow.Next = fast
    return dummy.Next
}
```

