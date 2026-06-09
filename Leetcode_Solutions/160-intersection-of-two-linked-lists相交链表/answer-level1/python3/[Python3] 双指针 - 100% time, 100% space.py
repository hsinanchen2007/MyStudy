## 分析：
- 两个指针分别从链表头开始扫描，每次分别走一步
- 若指针走到null，则从另一个链表头部开始走
- 两指针相同时:
    - (利用此时两个指针移动步数一致)
    - 指针不为null：指针位置为相遇点
    - 指针为null：两个链表不相交
## 代码：
```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        p, q = headA, headB
        while p != q:
            if p:
                p = p.next
            else:
                p = headB
            if q:
                q = q.next
            else:
                q = headA
        return p
```