### 解题思路
此处撰写解题思路
三个指针  left初始为None  head为头结点  right为下一个节点
每次迭代,head.next指向left，然后left指向head，head指向right，right指向right.next
直到right为None，head.next指向left  返回head

### 代码

```python
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseList(self, head):
        if head is None or head.next is None :
            return head
        right=head.next
        left=None
        while True:
            head.next=left
            left=head
            head=right
            right=right.next
            if right is None:
                head.next=left
                return head

        """
        :type head: ListNode
        :rtype: ListNode
        """
```