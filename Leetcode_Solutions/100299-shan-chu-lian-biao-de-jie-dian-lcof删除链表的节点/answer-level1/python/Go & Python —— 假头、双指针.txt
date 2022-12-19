### 几个注意点
1. 假头可以简化删除head的情况
2. 双指针可以避免.Next.Next的写法

### 代码
```go []
func deleteNode(head *ListNode, val int) *ListNode {
    dummy := &ListNode{Val: 0, Next: head} // 假头
    first := dummy // 双指针1
    second := dummy.Next // 双指针2
    for {
        if second.Val == val {
            first.Next = second.Next
            break
        }
        first = first.Next
        second = second.Next
    }

    return dummy.Next
}

```
```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0) # 假头
        dummy.next = head
        first = dummy # 双指针1
        second = dummy.next # 双指针2
        while True:
            if second.val == val:
                first.next = second.next
                break
            first = first.next
            second = second.next
        return dummy.next

```
