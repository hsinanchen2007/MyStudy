### 解题思路

1.temp指向原head下一个节点，防止丢失
2.head指向newHead的下一个节点
3.newHead指向head, 完成head节点插入到newHead和newHead下一节点之间的操作
4.将temp重新变为新head节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        newHead = ListNode(0)
        while head is not None:
            temp = head.next
            head.next = newHead.next
            newHead.next = head
            head = temp
        return newHead.next
```