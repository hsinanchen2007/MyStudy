### 解题思路
1. 双指针，将两个链表连接起来，相等的那个点就是交点
2. 遍历headA，将所有的点存储起来，当遍历headB的时候元素出现在set中，说明有重合，第一个点就是交点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        # a, b = headA, headB
        # while a != b:
        #     a = a.next if a else headB
        #     b = b.next if b else headA
        # return a

        s,p,q = set(),headA,headB
		#定义一个set之后，不断遍历p链表，然后将所有元素加入到set中
        while p:
            _,p = s.add(p),p.next
        while q:
            #遍历q链表，如果q链表的元素出现在set中，
            #就说明p和q两个链表有重合，
            #而这个重合的就是第一个相交的节点
            if q in s:
                return q
            q = q.next
        return None
```