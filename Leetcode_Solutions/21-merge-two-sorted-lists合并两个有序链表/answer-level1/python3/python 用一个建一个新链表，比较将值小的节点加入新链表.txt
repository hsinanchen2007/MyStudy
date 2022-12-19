这道题目没有算法难点，主要是对链表操作的熟悉。

注意几个点：
1. 如何判断链表是否为空？
    while l1, if l1, 都是用于判断链表是否为空的
2. 链表题在本地调试，直接print输出的是一个对象，可以通过debug模式看到具体的值，或者循环输出。
    给输入参数的时候也要给一个链表对象，不能直接给list,虽然leetcode网页里的输入输出看起来是list格式
3. 链表每个节点都是一个对象，所以加节点的时候不要加一个值，除了赋值外

```
# Definition for singly-linked list.
#class ListNode:
#    def __init__(self, x):
#        self.val = x
#        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        new_head = ListNode(0)
        new = new_head
        while l1 and l2:
            if l1.val <= l2.val:
                new.next = ListNode(l1.val)
                l1 = l1.next
                new = new.next
            else:
                new.next = ListNode(l2.val)
                l2 = l2.next
                new = new.next
        if l1:
            new.next = l1
        else:
            new.next = l2
        return new_head.next
```
