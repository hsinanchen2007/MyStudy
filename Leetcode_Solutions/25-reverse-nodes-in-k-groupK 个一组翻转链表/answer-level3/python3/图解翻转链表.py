![TIM图片20200105150846.png](https://pic.leetcode-cn.com/0c18a8d0f9de7160e283041085c795c97bc3fa0bf5498f28b1c828461b7418bf-TIM%E5%9B%BE%E7%89%8720200105150846.png)
大致思路如上图
记录前置指针、后置链表以及翻转部分链表节点，将翻转部分链表指针指向前置结点
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head:return None
        l=1
        mark=head
        while mark.next:
            l+=1
            mark=mark.next
        if l<k:return head
        n=l//k
        behead=ListNode(-1)
        behead.next=head
        start=behead
        for _ in range(n):
            openl=[]
            for _ in range(k):
                openl.append(start.next)
                start.next=start.next.next
            end=openl[-1].next
            start.next=openl[-1]
            for i in range(1,len(openl)):
                openl[-i].next=openl[-i-1]
            openl[0].next=end
            for _ in range(k):
                start=start.next
        return behead.next
```


