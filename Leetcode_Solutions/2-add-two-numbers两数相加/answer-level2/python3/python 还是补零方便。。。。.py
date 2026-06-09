### python3
代码还算简短

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        re = ListNode(0)
        head = re
        mod = 0
        while l1 and l2:
            re.val = (l1.val+l2.val+mod)%10
            mod = (l1.val+l2.val+mod)//10
            # 补零
            if l2.next and not l1.next:
                l1.next = ListNode(0)
            if l1.next and not l2.next:
                l2.next = ListNode(0)
            
            l1 = l1.next  
            l2 = l2.next
            if l1 and l2:
                re.next = ListNode(0)
                re = re.next
                
        if mod: re.next = ListNode(mod)
        return head

```