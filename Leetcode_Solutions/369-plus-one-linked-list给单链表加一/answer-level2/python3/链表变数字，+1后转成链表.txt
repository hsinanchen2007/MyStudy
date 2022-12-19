![微信图片_20200126223040.png](https://pic.leetcode-cn.com/62be78d9fc7503c97525bca5b6b76ee6e0c226411ac01de302de1f1f1a8f1fdc-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200126223040.png)
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        if head:
            num=head.val
            while head.next!=None:
                num=10*num+head.next.val
                head=head.next
        num+=1
        num=str(num)
        self.head=ListNode(num[0])
        p=self.head
        r=self.head
        for i in num[1:]:
            node=ListNode(i)
            p.next=node
            p=p.next
        return r
```

