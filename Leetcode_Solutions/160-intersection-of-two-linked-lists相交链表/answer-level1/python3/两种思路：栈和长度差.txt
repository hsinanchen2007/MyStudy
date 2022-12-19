思路一：把两个链表放入两个栈里，找到最后一个相同的结点。注意公共结点可能在某一个链表的开始。
```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        # 其中一个为空链表
        if not headA or not headB:
            return 
        s1 = []
        s2 = []
        while headA:
            s1.append(headA)
            headA = headA.next
        while headB:
            s2.append(headB)
            headB = headB.next
        length1 = len(s1)
        length2 = len(s2)
        node1 = []
        node2 = []
        # 跳出循环时，node1和node2里面有一个不相同的值，或者公共节点在某个链表的头节点
        while node1 == node2 and s1 and s2:
            node1.append(s1.pop())
            node2.append(s2.pop())
        # 进入一个元素，且这个元素不相同
        if len(node1) <= 1 and node1 != node2:
            return 
        # 数组相同
        if node1 == node2:
            return node1[-1]
        # 数组不相同，排除最后一个元素，其他为公共节点
        else:
            return node1[-2]
            
```

思路二：遍历链表的长度，长度差为k，长链表从k位置开始走，找到第一个公共结点
```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        m = 0
        node = headA
        while node:
            node = node.next
            m += 1
     
        n = 0
        node = headB
        while node:
            node = node.next
            n += 1
    
        if m < n:
            k = n - m
            while k:
                k -= 1
                headB = headB.next
        else:
            k = m - n
            while k:
                k -= 1
                headA = headA.next
        while headA != headB:
            headA = headA.next
            headB = headB.next
        return headB
```
