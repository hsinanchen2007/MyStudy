观察最后链表可知，这个链表被分成两种情况，序号在前面的顺序不变，序号在后面的倒叙插入。简单的思路就是利用快慢指针先将链表划分为两个子链表，然后将后者进行链表转置，最后对两个子链表进行按序插入即可
```
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        res = head

        if head == None:
            return
        low = head
        fast = head.next
        while fast:
            low = low.next
            fast = fast.next
            if not fast:
                break
            fast = fast.next
        head2 = low.next
        low.next = None
        if head2==None:
            return
        pos = head2.next
        head2.next=None
        while pos:
            temp = pos
            pos = pos.next
            temp.next = head2
            head2 = temp
        while head2:
            temp = head2
            head2 = head2.next
            temp.next = head.next
            head.next = temp
            head = temp.next
```
![34d34cfac6927511c8026c59f60c134.png](https://pic.leetcode-cn.com/4d414c7c3926945024eee8824c576f01481307acfca3c8b43060ad44f6d5f228-34d34cfac6927511c8026c59f60c134.png)



