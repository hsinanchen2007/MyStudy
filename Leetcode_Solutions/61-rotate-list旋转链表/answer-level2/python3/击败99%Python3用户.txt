
```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        #定义遍历指针
        p=head
        #首先计算链表的长度
        len=0
        while p:
            p=p.next
            len+=1
        p=head
        for i in range(k%len):
            p=p.next 
        #再定义一个指针p2，与p一起将需要移动的节点段表示出来
        p2=head
        while p.next:
            p=p.next
            p2=p2.next
        p.next=head
        head=p2.next
        p2.next=None
        return head
        
```

