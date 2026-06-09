### 解题思路
1、这题直接ans=ListNode()的话会导致结果最后面出现"Null"，所以先把链表第一位的值给到ans
2、基于1，所以要先判断链表是否为空

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head: return None
        ans = ListNode(head.val)
        cnt = head.next
        while cnt != None:
            temp = cnt.next
            cnt.next = ans
            ans = cnt
            cnt = temp                   
        return ans
```