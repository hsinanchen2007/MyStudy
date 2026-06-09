
递归，每次处理前k个元素

执行用时 :64 ms, 在所有 Python3 提交中击败了92.88%的用户
内存消耗 :14.9 MB, 在所有 Python3 提交中击败了5.15%的用户


```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        p=head
        def gen(p):
            h=p
            if p:
                i=1
                while p.next and i<k:
                    p=p.next
                    i+=1

                if i==k:                   
                    p=h.next
                    q=h
                    for j in range(k-1):
                        w=p.next 
                        p.next=q                     
                        q=p
                        p=w                   
                    h.next=gen(p)
                    return q   
            return h
```
