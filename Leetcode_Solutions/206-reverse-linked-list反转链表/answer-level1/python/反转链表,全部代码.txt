### 解题思路
此处撰写解题思路

### 代码

```python

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head):
        pre = None
        while head:
            tmp = head.next  # 备份head.next
            head.next = pre
            pre = head
            head = tmp
        return pre


l1 = ListNode(1)
b = ListNode(2)
c = ListNode(3)
l1.next = b
b.next = c
a = Solution()
k = a.reverseList(l1)
while k:
    print(k.val)
    k = k.next

```