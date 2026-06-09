### 解题思路
通过两个指针判定删除元素，a指针指向 head，b指针为 head.next。 
判定：
如果 a.val == b.val b移动。
如果 a.val != b.val, a移动，并用 b.val 替代，之后 b移动。
如果 b = None 结束。 a.next = None

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        a = head
        b = head.next
        while b != None:
            if a.val != b.val:
                a = a.next
                a.val = b.val
            b = b.next
        a.next = None
        
        return head

```