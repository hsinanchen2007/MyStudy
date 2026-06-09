1. 定义两个子函数
    1.1 切割函数，取出两个节点
    1.2 反转函数， 反转链表
2. 伪代码
```
    dummy = ListNode(0)
    tail = dummy  tail用来串起来切割后并排序的链表
    while pre：(pre切割后的链表的头节点)
        切割
        反转
        tail串起
    return dummy.next
```

3. 具体实现
```
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:

        #链表反转，+链表切割
        step = 2
        p = head
        n = 0
        dummy = ListNode(0)
        tail = dummy
        while p:
            n = n+1
            p = p.next
        pre = head
        while pre:
            cur = self.cut(pre,2)
            tail.next = self.reverse(pre)
            pre = cur
            while tail.next:
                tail = tail.next
        
        return dummy.next

    
    def reverse(self,head):
        #交换一个或者两个链表，并返回头部
        if not head or not head.next:
            return head
        else:
            nex = head.next
            nex.next = head
            head.next = None
            return nex

    def cut(self,head,n):
        i = 0
        pre = ListNode(0)
        pre.next = head
        while i < n and head:
            head = head.next
            pre = pre.next
            i = i + 1
        pre.next = None
        return head
```
