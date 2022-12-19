### 解题思路
递归的第一步通常考虑如何跳出循环：
第一步：当链表为空或next为空时返回NULL
第二步：否则递归获取当前节点之后链表的反转链表temp
第三步：设计需要递归循环执行的代码，实现：
    1. 反转当前节点和下一个节点，下一个节点是由第一步返回的NULL或者由2返回的空指针节点   
    **注意：此步操作( head.next.next = head)会同时修改temp.next**
    2. 删除当前节点的指针，使其成为1中的下一个节点，避免产生死循环   
    **注意：此步操作(head.next = None)会同时修改temp.next.next**
    3. 返回temp

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
        if not head or head.next is None:
            return head
        temp = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return temp

```