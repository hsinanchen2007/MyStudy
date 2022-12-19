### 暴力法

基本思路：一遍循环求长度， 一遍循环找中值，时间复杂度一般，空间复杂度非常好。代码如下：

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        count = 0
        p = head
        while p is not None:
            count += 1
            p = p.next
            
        count = count//2
        p = head
        while count > 0:
            p = p.next
            count -= 1
            
        return p
            
            
```

### 双指针法

时间复杂度度O(n), 空间复杂度O(l)。采用一个快指针和一个慢指针，快指针是慢指针的两倍，当快指针到链表末尾时，则慢指针处在中间位置。代码如下：

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if head == None or head.next==None:
            return head
        p = head
        q = head.next
        while q.next is not None and q.next.next is not None:
            p = p.next
            q = q.next.next
            
        return p.next
            
            
```