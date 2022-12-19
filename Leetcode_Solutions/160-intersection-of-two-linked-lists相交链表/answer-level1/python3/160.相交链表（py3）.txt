双指针法
1：先计算两个链表的长度m,n；
2：把两个指针分别指向两个链表的头部；
3：先移动长链表上的指针（假设m>n），移动m-n个节点，移动之后此时指针到尾部的长度也为n了；
4: 再同时移动两个指针，当第一次相遇时即为第一个节点。
```python []
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        
        lenA ,lenB = 0 , 0
        node1, node2 = headA, headB
        while node1:
            lenA += 1
            node1 = node1.next
        while node2:
            lenB += 1
            node2 = node2.next
            
        node1, node2 = headA, headB
        while lenA > lenB:
            node1 = node1.next
            lenA -= 1
        while lenB > lenA:
            node2 = node2.next
            lenB -= 1
        while node1 is not node2:
            node1 = node1.next
            node2 = node2.next
        return node1