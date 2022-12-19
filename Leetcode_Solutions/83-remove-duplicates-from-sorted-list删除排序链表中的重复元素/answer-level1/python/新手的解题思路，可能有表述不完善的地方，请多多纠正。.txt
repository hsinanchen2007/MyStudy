### 解题思路
此处撰写解题思路
一.首先判断head是否为空或者head.next为空，两者有一个为空就直接返回 head，因为不可能有重复

二.然后就是head不为空的情况：

将tmp指向head，re指向head的下一个。
如果tmp.val==re.val：
1.首先判断re是不是最后一个节点,如果是就直接令tmp的下一个节点等于None然后结束循环
2.如果不是最后一个节点，则令tmp的下一个节点指向下下一个节点，相当于删除了重复的节点。然后re指向下一个结点，然后继续比较
如果不等于：
1.直接把tmp与re都往后移一个节点，继续比较，直到遍历完整个链表，结束循环
返回head
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None or head.next==None:return head 
        tmp = head
        re = head.next
        while re:
            while (tmp.val == re.val):
                if  (re.next)==None:
                    tmp.next = None
                    break
                else:      
                    tmp.next = re.next
                    re = re.next
            tmp = re
            re = re.next
               
        return head
```