### 解题思路
快慢双指针。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if not (head and head.next):
            return False

        slow, fast = head, head.next
        # print slow, fast

        while fast and fast.next:
            if slow == fast:
                return True
            slow = slow.next
            fast = fast.next.next

        return False
```


### 解题思路
把见过的节点丢集合里，下次再遇见就是环的开始。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if not (head and head.next):
            return False

        s = {None}
        while head not in s:
            s.add(head)
            head = head.next
        if not head:
            return False
        else:
            return True
```