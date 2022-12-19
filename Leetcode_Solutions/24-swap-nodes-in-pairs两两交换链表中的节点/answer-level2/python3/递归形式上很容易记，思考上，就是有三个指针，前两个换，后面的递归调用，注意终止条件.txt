### 解题思路
递归形式上很容易记，思考上，就是有三个指针，前两个换，
head, head.next = head.next, head
后面的递归调用
head.next.next = self.swapPairs(head.next.next)
注意终止条件
if not head or not head.next:
    return head
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        else:
            head, head.next, head.next.next = head.next, head, self.swapPairs(head.next.next)

        return head
```