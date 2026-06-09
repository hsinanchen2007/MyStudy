### 直接法1

其实两种方法基本一样......，但是第一种方法将target改成是一个数组，存储所有的曾经出现过的值，就可以用在无序链表中。

`当p的下一个元素是重复元素，则p.next = p.next.next`
代码如下：
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None or head.next== None:
            return head        
        p = head
        target = p.val
        while True:
                
            if p.next.val == target:
                p.next = p.next.next                
            else:
                target =p.next.val
                p = p.next
                
            if p.next is None:
                break
                
        return head
                
            
```

### 直接法2

因为是有序链表，所以直接一遍遍历就可以完成。

`当p.val = p.next.val时，则跳过p.next: p.next = p.next.next`

```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None or head.next== None:
            return head        
        p = head
        while True:
            if p.val == p.next.val:
                p.next = p.next.next
            else:
                p = p.next
            if p.next==None:
                break
            
        return head
```