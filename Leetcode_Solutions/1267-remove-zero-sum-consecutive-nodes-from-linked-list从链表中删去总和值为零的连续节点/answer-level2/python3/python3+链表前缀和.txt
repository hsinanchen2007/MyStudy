### 解题思路
对链表求前缀和，然后第一次找出从头节点开始的和为0的连续节点，第二次找出不是以头节点开始的和为0的连续节点，最后在把链表还原即可

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        pre = tail = ListNode(0)
        tail.next = head
        cur = head
        while cur != None:
            cur.val += pre.val
            if cur.val == 0:
                tail.next = cur.next
                cur = tail.next
                pre = tail
            else:
                pre = cur
                cur = cur.next
        cur = tail.next
        d = {}
        while cur != None:
            if cur.val not in d:
                d[cur.val] = cur
                cur = cur.next
            else:
                d[cur.val].next = cur.next
                d = {}
                cur = tail.next
        pre = 0
        cur = tail.next
        while cur != None:
            tmp = cur.val
            cur.val -= pre
            pre = tmp
            cur = cur.next
        return tail.next
```