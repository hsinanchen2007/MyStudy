### 解题思路
两次遍历：
第一次遍历记录链表的长度，第二次遍历直接删除节点。


### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """

        dummy = ListNode(0)
        dummy.next = head      
        first = dummy
        second = dummy

        num_node = 0
        while first.next:
            first = first.next
            num_node += 1

        for i in range(num_node-n):
            second = second.next
        second.next = second.next.next

        return dummy.next

```



### 解题思路
一次遍历：
使用快慢指针，快指针先移 n 个节点。
接下来，快慢指针一起移动，两指针之间一直保持 n 个节点，当快指针到链表底了，操作慢指针，删除要删除的元素！
时间复杂度：O(n)



### 代码

```python
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:return 
        dummy = ListNode(0)
        dummy.next = head
        slow = dummy
        fast = dummy 
        
        for i in range(n):
            fast = fast.next
        # print fast.val

        while fast and fast.next:
            fast = fast.next
            slow = slow.next
        
        slow.next = slow.next.next

        return dummy.next
```