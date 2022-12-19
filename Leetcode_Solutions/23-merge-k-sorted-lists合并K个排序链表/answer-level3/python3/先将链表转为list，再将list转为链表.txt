### 解题思路
先将链表转为list，再将list转为链表。
另外要考虑初始链表为空的情况

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        ll_val = []
        for i in lists:
            while i :
                ll_val.append(i.val)
                i = i.next
        ll_val.sort()
        merged_node=None
        for i in range(len(ll_val)):
            if i == 0:
                merged_node = x = ListNode(ll_val[i])
            if i != len(ll_val)-1:
                x.next = ListNode(ll_val[i+1])
                x = x.next
        return merged_node
```