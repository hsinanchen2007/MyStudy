一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
这题应该是删除节点的操作是O(1)吧，如果是删除节点值感觉做不了O(1).

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head.val == val: 
            head = head.next
        p = ListNode(0)
        p.next = head
        while head and head.next:
            if head.next.val == val:
                head.next = head.next.next
            head = head.next
        return p.next
```