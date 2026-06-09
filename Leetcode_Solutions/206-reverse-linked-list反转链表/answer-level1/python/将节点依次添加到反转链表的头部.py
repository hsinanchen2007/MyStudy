```python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 反转链表的头节点
        result = None
        # 遍历链表
        while head is not None:
            # head 作为遍历旧链表的指针
            temp = head.next
            # 将节点依次添加到反转链表的头部
            head.next = result
            result = head
            head = temp
        return result
```