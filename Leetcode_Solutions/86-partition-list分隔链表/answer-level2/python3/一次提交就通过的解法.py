### 解题思路
解题过程：
两个头结点low和high，一个指向小于targetValue的节点；一个指向其他的节点。遍历链表，low和high生成两个新的链表。

关键点：
high链表中不能有小于targetValue的节点，否则会行程环。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        low = ListNode(-1)
        high = ListNode(-1)
        
        dumbLow = low
        dumbHigh = high
        
        while head is not None:
            # 判断当前节点是否小于targetValue
            if head.val < x:
                # 小值放入low链表
                dumbLow.next = head
                dumbLow = dumbLow.next
                if dumbHigh.next == head:
                    dumbHigh.next = None
            else:
                dumbHigh.next = head
                dumbHigh = dumbHigh.next
            head = head.next
            
        dumbLow.next = high.next
        
        return low.next
```
