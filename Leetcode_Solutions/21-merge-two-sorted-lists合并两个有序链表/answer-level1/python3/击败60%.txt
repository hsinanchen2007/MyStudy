```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode(0)
        if not l1:
            return(l2)
        elif not l2:
            return(l1)
        else:
            first = l3
            while l1 != None or l2 != None:
                if l1 != None and l2 != None:
                    if l1.val <= l2.val:
                        first.next = ListNode(l1.val)
                        first = first.next
                        l1 = l1.next
                    else:
                        first.next = ListNode(l2.val)
                        first = first.next
                        l2 = l2.next
                elif l1 != None:
                    first.next = l1
                    l3 = l3.next
                    return(l3)
                else:
                    first.next = l2
                    l3 = l3.next
                    return(l3)
        
```
不能在自己的测试环境中敲代码真是不方便
此题是笔者第二次解链表，解法是自己琢磨的：
笔者发现链表有一个特性，（不知道理解是否有问题）：
链表需要有一个标签去标识，比如l3 = ListNode(0),那么l3就可以看作此单链表的标识，如果我们想遍历比较此链表，
可以使用另一个变量，比如first = l3,作用是first = first.next 不会修改l3标识链表的内容；但如果使用
l3 = l3.next；则意味着不要此单链表的头节点
