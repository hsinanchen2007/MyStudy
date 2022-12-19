### 解题思路
- 将链表前K个节点与后续节点断开；
- 将前K个节点进行链表反转；
- 将反转后的链表与后续节点连接；
***通过指针来记录每个关键节点的位置***

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverse(self, head):
        # 链表反转算法
        pre = None
        cur = head
        while cur:
            nex = cur.next
            cur.next = pre
            pre = cur
            cur = nex
        return pre

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next:
            return head
        new_head = ListNode(-1)
        new_head.next = head
        # 双指针法
        pre = end = new_head
        while end.next:
            # 将end指针移到第k个节点处
            # 期间判断是否超出链表长度，超出则直接跳出循环
            for i in range(k):
                if end:
                    end = end.next
            if not end:
                break
            # 设置p1和p2指针，分别指向pre和end的下一位
            # 将end与p2的关系断开，再将p1到end之间的链表反转，最后将反转后的链表末端p1与p2连起来
            p1, p2 = pre.next, end.next
            end.next = None
            pre.next = self.reverse(p1)
            p1.next = p2
            # 继续移动pre和end指针，进行下一组k个节点的反转
            pre = end = p1
        return new_head.next
                

        
```