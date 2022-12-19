双重遍历，y指向当前结点，x指针右移n次，若x是尾结点则删除y.next，若x==None，则删除头结点。
```
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        y = head
        while y:
            x = y
            count = 0
            while count < n:        # 找删除点
                if x is not None:
                    x = x.next
                else:
                    break
                count += 1
            if count < n:   # 输入的数字>链表长度
                return head
            elif x is None:     # 删除链表头
                head = y.next
                return head
            elif x.next is None:      # 确认是删除点  
                y.next = y.next.next
                return head
            y = y.next
        return head
```
