```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        a, b = (headA, headB) if headA and headB else (None, None)
        while a != b: a, b = not a and headB or a.next, not b and headA or b.next
        return a
```
这题不支持 Python3 所以只能用 Python2 做了

把第一条链表的尾部接到第二条链表的开头，第二条接到第一条的开头，就能消除俩条链表的长度差，并在某一时刻在第一个交叉点相遇，或在走完俩条链表长度的时候同时为 None
- 假设有两条链表1→2→3→4和①→②→③，模拟一下算法流程 ↓
```python
1 → 2 ↘  ↗ → 4                                    1 → 2 ↘  ↗ → 4 → ① → → → 3(②) ❤ 相遇了
① → → 3(②) → ③   把4接到①前面，把③接到1前面   ① → → 3(②) → ③ → 1 → 2 ↗   若非相交链表则同时走到None
```

