### 解题思路
如果两个链表相交，那么两个指针从两个表头同时开始走，第一次遇到链尾时跳到另一个链头，一定会在相交处相遇，如果链表不相交，那么两个指针会同时指向两个表尾后的null。

### 代码

```python3
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        
        A, B = headA, headB
        
        while A != B:
            A = A.next if A else headB
            B = B.next if B else headA

        return A
```