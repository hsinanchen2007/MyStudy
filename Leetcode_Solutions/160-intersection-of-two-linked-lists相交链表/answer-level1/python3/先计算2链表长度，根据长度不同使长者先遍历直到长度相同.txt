### 解题思路
我的时间复杂度应该是O（max(len(a)、len(b)）吧，也没有辅助空间。为什么用时228ms 内存28.5MB？

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        #求链表长度
        def getLen(head):
            p=head
            len=0
            while p:
                p=p.next
                len+=1
            return len
        lena=getLen(headA)#A表长
        lenb=getLen(headB)#B表长
        p=headA
        q=headB
        if lena>lenb:#调整，A表节点先走lena-lenb个长度
            for i in range(lena-lenb):
                p=p.next
        elif lena<lenb:#调整，B表节点先走lenb-lena个长度
            for i in range(lenb-lena):
                q=q.next
        while p:#两表同步遍历
            if p==q:
                return p
            else:
                p=p.next
                q=q.next
        return None

```