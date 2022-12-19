### 解题思路
双指针法：
### 代码

```python
class Solution:
    def getIntersectionNode(self, headA, headB):
        if not headA or not headB: return None
        pa, pb = headA, headB
        while pa != pb:
            pa = pa.next if pa else headB
            pb = pb.next if pb else headA
        return pa 
```

### 解题思路
把a的尾部接到b的头部，如果相交则成了环。利用[环形链表II](https://leetcode-cn.com/problems/linked-list-cycle-ii/submissions/)里的flyod法判断入环的第一个点
### 代码

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB: return None
        slow, fast = headA, headA
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        tail_a = fast.next if fast.next else fast
        tail_a.next = headB

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                break

        if not fast.next or not fast.next.next: 
            tail_a.next = None
            return None

        p1, p2 = headA, fast
        while p1 != p2:
            p1, p2 = p1.next, p2.next
        tail_a.next = None
        return p1
```