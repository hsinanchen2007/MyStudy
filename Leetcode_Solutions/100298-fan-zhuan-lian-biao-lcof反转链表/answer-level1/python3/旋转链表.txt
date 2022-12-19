### 解题思路
建立三个指针：l_pre,l,l_last，首先断掉l与l_last的链，然后连接l与l_pre的链，循环到最后

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        l = head
        if l == None:
            return None
        else:
            l_pre = head
            l_last = l_pre.next
            l = l_last
            l_pre.next = None
            while l_last != None:
                l =l_last
                l_last=l.next
                l.next = l_pre
                l_pre = l 
            l = l_pre
            return l


```