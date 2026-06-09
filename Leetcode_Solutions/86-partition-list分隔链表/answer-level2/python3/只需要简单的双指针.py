### 解题思路
双指针，注意逻辑细节:只有大的，没有小的，反之。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if head is None:
            return head

        smaller = None
        bigger = None
        bigger_head = None
        new_head = None

        while head != None:
            if head.val < x:
                if smaller == None:
                    smaller = ListNode(head.val)
                    new_head = smaller
                else:
                    smaller.next = ListNode(head.val)
                    smaller = smaller.next
            else:
                if bigger == None:
                    bigger = ListNode(head.val)
                    bigger_head = bigger
                else:
                    bigger.next = ListNode(head.val)
                    bigger = bigger.next
            head = head.next
            if head == None and bigger is not None:
                bigger.next = None
        if smaller == None and bigger_head is not None:
            new_head = bigger_head
        else:
            smaller.next = bigger_head
        return new_head

        # 1 2 2 4 3 5 
```