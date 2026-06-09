### 蠢方法，先转化为列表...

时间复杂度时空时坏，空间复杂度一塌糊涂......

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None:
            return head
        target = []
        p = head
        while p is not None:
            target.append(p.val)
            p = p.next
        
        n = len(target)
        head = ListNode(target[n-1])
        L = head
        for i in range(n-2,-1,-1):
            
            L.next = ListNode(target[i])
            L = L.next
            
        return head
            
```

### 逐步调换1

时空复杂度跟上面差不多。基本思路就是遍历，逐渐调换顺序，比如先调换前两个，再调换前三个，但是新建了一个链表（空间复杂度比较高）。以此类推...

```

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        p = ListNode(head.val) 
        q = ListNode(head.next.val)
        q.next = p
        r = head.next.next
        while r is not None:
            tmp = ListNode(r.val)
            tmp.next = q
            q = tmp
            r = r.next   
        return q
        
```

### 逐步调换2

采用1个变量q临时存储的方式，将后面的元素逐个的移到链表的最前面。

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        p = head
        r = p
        while r is not None:
            if r.next.next is not None:
                q = r.next
                r.next = r.next.next
                q.next = p
                p = q
            else:
                q = r.next
                r.next = r.next.next
                q.next = p
                p = q
                break
        return p
```

实际上有点又臭又长，毕竟菜...