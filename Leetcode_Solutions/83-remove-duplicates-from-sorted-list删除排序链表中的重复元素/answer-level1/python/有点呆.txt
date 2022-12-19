### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head==None:
            return None
        course=head
        while course.next !=None:
            if course.val==course.next.val:
                course.next=course.next.next
            else:
                course=course.next
        return head
```