#双指针方法
```python []
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode: 
        if head is None:
            return head
        
        ahead, bhead = ListNode(0), ListNode(0)   #建两个空结点，放到链表头部
        aTail, bTail = ahead, bhead  #再建两个指针，指向放在头部的空结点
        
        while head is not None:  #当链表中结点的val域不为空时
            if head.val < x:   # a指针用来串起来所有小于x的结点
                aTail.next = head
                aTail = aTail.next   #指针往后移动
            else:
                # b指针用来串起来所有大于等于x的结点
                bTail.next = head
                bTail = bTail.next
            #串一个结点之后，原头指针往后移动一个节点
            head = head.next
        #while循环结束之后， 将两个部分拼接起来
        bTail.next = None
        aTail.next = bhead.next
        return ahead.next