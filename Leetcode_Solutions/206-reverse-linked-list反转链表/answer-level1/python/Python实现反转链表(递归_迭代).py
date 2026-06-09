### 解题思路
1. 递归
    p1->p2->p3->p4->p5->null
    结果链表头结点定义为new_head
    当我们知道头结点p1之后的链表的反转时(p5->p4->p3->p2->null),此时只需要把p2->next=p1 p1->next=null就可以了
2. 迭代
    a) 暴力解决
        dummy(node)->p1->p2->p3->p4->p5(last)->null
        定义一个dummy头结点(node), last定义为链表的尾结点.
        每次都将node.next链接到当前的last, 然后更新node, last
        结果: 时间复杂度比较高(O(n^2))
    b) 反向链接
        null<-p1<-p2<-p3<-p4<-p5
        定义一个prev, 初始化为null, 每次都将当前的head指向prev. 

### 代码: 递归

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
        # prev = None
        # while head:
        #     next = head.next
        #     head.next = prev
        #     prev = head
        #     head = next
        # return prev

        if head is None or head.next is None:
            return head
        next = head.next
        new_head = self.reverseList(next)
        next.next = head
        head.next = None
        return new_head
```

### 代码: 迭代(非暴力)

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
        prev = None
        while head:
            next = head.next
            head.next = prev
            prev = head
            head = next
        return prev

```