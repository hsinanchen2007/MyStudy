### 解题思路
首先遍历链表算出长度，然后计算中间值，最后再次遍历链表当指针走到中间值时，截断链表返回

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        j =0
        result = []
        temp_head = head
        while temp_head:
            result.append(temp_head.val)
            temp_head = temp_head.next
            j +=1
        k = int(j/2)
        i = 0
        while i <j:
            if i<k:
                i +=1
                head = head.next
            else:
                temp_head=head
                break
        return temp_head
```