### 解题思路
思路一：
将原链表元素挨个取出来放进数组中，然后构建一个新链表，将数组元素逆序取出放进新链表。
这样做需要两个额外的空间。
思路二：
将原链表元素挨个取出来放进数组中，然后将数组元素逆序取出，更改原链表的值。
这样做仍然需要一个额外的空间。
思路三：
借鉴了大神的思路，使用两个指针，将原链表逆序过来。

我太菜了，加油！

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is not None:
            new_head = None
            tmp = head
            while tmp is not None:
                tmp = head.next
                head.next = new_head
                new_head = head
                head = tmp
            return new_head
        else:
            return head
```