### 解题思路
	first_head指向大于等于x的子链表头结点(第一个节点是哑结点)，first_tail指向其尾结点；
	second_head指向小于x的子链表头结点(第一个节点是哑结点)，second_tail指向其尾结点；
	将两链表连起来，返回头结点，注意不要包含哑结点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if head==None:
            return
        first_head=first_tail=ListNode(-1)
        second_head=second_tail=ListNode(-1)
        cur=head
        while cur:
            if cur.val>=x:
                first_tail.next=cur
                first_tail=first_tail.next
                cur=cur.next
                first_tail.next=None
            else:
                second_tail.next=cur
                second_tail=second_tail.next
                cur=cur.next
                second_tail.next=None
                
        second_tail.next=first_head.next
        return second_head.next






```