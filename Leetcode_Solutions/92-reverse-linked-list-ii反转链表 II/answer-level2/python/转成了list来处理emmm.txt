### 解题思路
我这个小菜鸟每次都转成list来处理。。。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head,m,n) :
        A = []
        while head:
            A.append(head.val)
            head = head.next
        B = A[m-1:n]
        B.reverse()
        for i in range(n-m+1):
            A[i+m-1] = B[i]
        head = ListNode(A[0])
        root = head
        for i in range(1,len(A)):
            hh = ListNode(A[i])
            head.next = hh
            head = head.next
        return root
```