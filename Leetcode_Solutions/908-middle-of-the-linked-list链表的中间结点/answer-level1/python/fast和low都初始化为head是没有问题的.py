### 解题思路
1、fast每次2步，low每次1步；
2、fast和head都初始化为head是可以的；
3、while fast and fast.next；

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None

        low = head
        fast = head

        while fast and fast.next:
            low = low.next
            fast = fast.next.next

        return low

```