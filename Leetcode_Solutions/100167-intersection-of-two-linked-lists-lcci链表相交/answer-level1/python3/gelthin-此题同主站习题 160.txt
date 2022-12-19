### 解题思路
此题同主站习题 [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)
可以参见题解 [gelthin-巧妙解法](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/gelthin-qiao-miao-jie-fa-by-gelthin/)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if (headA == None) or (headB == None):
            return None
        a, b = headA, headB
        while a != b:
            a = a.next if a != None else headB
            b = b.next if b != None else headA
        if a == None:
            return None
        else:
            return a
```