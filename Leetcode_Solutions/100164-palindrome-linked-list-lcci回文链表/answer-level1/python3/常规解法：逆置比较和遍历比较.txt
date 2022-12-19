### 解题思路
方法一：头插法逆置比较
方法二：遍历到list中，然后逆置比较
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:

    def isPalindrome(self, head: ListNode) -> bool:
        sub = head
        head2 = ListNode(0)

        # 头插法逆置链表
        while sub:
            q = ListNode(sub.val)

            t = head2.next
            head2.next = q
            head2.next.next = t

            sub = sub.next

        # 进行比较
        cur1 = head
        cur2 = head2.next
        while cur1 and cur2:
            if cur1.val != cur2.val:
                return False
            cur1 = cur1.next
            cur2 = cur2.next
        return True

    def isPalindrome2(self, head: ListNode) -> bool:
        l = []
        sub = head
        while sub:
            l.append(sub.val)
            sub = sub.next
        return l == l[::-1]
```