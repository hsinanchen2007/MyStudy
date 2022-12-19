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
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if k == 0:
            return head
        temp = head
        length = 0
        if head == None:
            return head
        while temp.next != None:
            length += 1
            temp = temp.next
        length += 1
        temp.next = head
        temp = head
        for i in range((length - k%length -1)):
            temp = temp.next
        new_head = temp.next
        temp.next = None
        return new_head
```

需要搞清楚数学规则，知道两个互为模数就行了
