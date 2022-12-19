```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        st=[]
        n=ListNode(-1)
        t=n
        while head:
            i=1
            while head and i<=k:
                st.append(head)
                head=head.next
                i+=1
            if i==k+1:
                while st:
                    t.next=st.pop()
                    t=t.next
                if not head:#正好被k整除的话,最后一个节点next值为None
                    t.next=None
            else:
                if st:
                    t.next=st[0]
        return n.next
```
