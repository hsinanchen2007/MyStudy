### 解题思路
解题思路：双指针
第一步：快慢指针找到链表中间位置
第二步：翻转链表后半部分
第三步：前后两部分进行比较，判断是否为回文链表
注意：从两头往中间比较，所以可以忽略奇偶性，如果是奇数，最中间一个节点不参与比较
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None or head.next is None:
            return True

        p1 = head
        p2 = head

        # 快慢指针找到链表中间位置
        while p2.next is not None and p2.next.next is not None:
            p1 = p1.next
            p2 = p2.next.next

        # 翻转链表后半部分
        p2 = p1.next
        p1.next = None
        p1 = None
        while p2 is not None:
            p3 = p2.next
            p2.next = p1
            p1 = p2
            p2 = p3

        # 前后两部分进行比较，判断是否为回文链表
        # 从两头往中间比较，所以可以忽略奇偶性，如果是奇数，最中间一个节点不参与比较
        p2 = head
        while p1 and p2:
            if p1.val != p2.val:
                return False
            p1 = p1.next
            p2 = p2.next

        return True
```