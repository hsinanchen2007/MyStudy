### 解题思路
遍历了三次，效率不太高

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # if n == 1:
        #     while head:
                
        pre = reverse(head)
        k = 0
        res = ListNode(0)
        res.next = pre
        while pre:
            if n == 1:
                res.next = pre.next
                break
            k += 1
            if k < n-1:
                pre = pre.next
                if pre == None: return None
                continue
            pre.next = pre.next.next
            break
        return reverse(res.next)

def reverse(head):
    pre = None
    while head:
        nexttemp = head.next
        head.next = pre
        pre = head
        head = nexttemp
    return pre


            

```