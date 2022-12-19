### 解题思路
思路：同时遍历两个链表，比较指针节点的大小，小的就添加进新链表中。需要注意如果指针有一个先到结尾了，那么另一个就可以直接添加进新链表的尾部了
伪代码：
先为两个链表分别设置指针pre、cur，指向头节点；
为新链表设置一个指针tra，指向头节点；
当pre和cur同时不为None时：
        如果pre的值小于等于cur，那么久将pre添加进新链表尾端，同时移动指针pre、tra指向后继节点;
        否则，将cur添加进新链表尾部，同时移动指针cur、tra指向后继节点;
当pre、cur有一个为None时，判断选择不为None的指针，直接把它添加进新链表尾部;
因为head为None，添加的节点是从head的后继节点开始，所以返回值要为head.next。


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        '''分别为l1和l2设两个指针，pre和cur'''
        pre = l1
        cur = l2
        head = ListNode(None)
        '''为新链表设一个指针tra'''
        tra = head
        while pre and cur != None:
            if pre.val <= cur.val:
                tra.next = pre
                pre = pre.next
                tra = tra.next
            else:
                tra.next = cur
                cur = cur.next
                tra = tra.next
        if pre == None:
            tra.next = cur
        else:
            tra.next = pre
        return(head.next)


```