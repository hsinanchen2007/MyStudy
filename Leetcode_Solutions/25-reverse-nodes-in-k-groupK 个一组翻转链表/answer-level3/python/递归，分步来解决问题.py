### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        def reverse(a,b):#反转列表
            pre = ListNode()
            cur = a
            nex = a
            while cur != b:
                nex = cur.next
                cur.next = pre
                pre = cur
                cur = nex
            return pre
        a = b = head
        for i in range(k):
            if not b:return head#若链表短于k,则不进行反转
            b = b.next
        new_node = reverse(a,b)#得到的起始位置
        a.next = self.reverseKGroup(b,k)#a就变为尾节点
        return new_node
```