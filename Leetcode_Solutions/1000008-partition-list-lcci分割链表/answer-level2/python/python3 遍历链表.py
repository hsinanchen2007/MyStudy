### 解题思路
保存第一个大于等于x的节点的位置，遍历链表，将后面出现小于x的节点连接到刚刚保存的那个节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        #思路：我们先找到第一个大于等于x的节点，将后面小于x的节点移动过来
        if head == None:
            return None
        pre_head = ListNode(-1)
        pre_head.next = head
        pre = pre_head
        cur = head
        while cur and cur.val < x:
            pre = cur 
            cur = cur.next
        if cur == None:
            return pre_head.next
        #cur是要连接的节点，pre是前一个节点
        right = cur.next
        left = cur
        while right:
            if right.val < x:
                left.next = right.next
                right.next = cur
                pre.next = right
                pre = right
                right = left.next
            else:
                left = right
                right = right.next
        return pre_head.next
        
```