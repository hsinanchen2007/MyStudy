```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        p = head
        # 双重循环，避免出现1,1,2,2....
        while p and p.next and p.val == p.next.val:
            while p and p.next and p.val == p.next.val:
                p = p.next
            p = p.next

        head = p # 此时head必为唯一结点

        if not head:
            return head
 
        q = p
        while q.next and q.next.next:
            flag = False
            while q.next and q.next.next and q.next.val == q.next.next.val:
                flag = True
                q.next = q.next.next
            if flag:
                q.next = q.next.next # 因为不保留重复的，所以把重复的最后一个元素删除
            else:
                q = q.next

        return head


            


        

```
