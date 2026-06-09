递归方法实现

```
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head                             // 终止条件
    }
    head.Next  = deleteDuplicates(head.Next)     // 递归调用
    if head.Val == head.Next.Val {                    
        head = head.Next                      // 去重
    }
    return head
}
```


