双指针的解法，时间和空间能满足要求
第一步：由于从相交的节点开始，链表后的长度就一样的了，所以可以先统计两个链表的长度，再将A、B的指针移到相同的起点，比如A:[4,1,8,4,5]和B:[5,0,1,8,4,5]，将A的指针指向A的头，B的指针指向0所在的节点，这就是我说的相同的起点；
第二步：起点相同了就可以顺序变量，找到第一个相交的节点并返回，没有找到，返回None
（可能这种解答并不是最好的，但是真的就是突然发现这样好像可以解）
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        #找到比较的起点
        #统计两个链表的节点个数
        a,b = 0,0
        p = headA
        while p:
            a+=1
            p=p.next
        p = headB
        while p:
            b+=1
            p=p.next
        p = headA
        q = headB
        if a>b: 
            l = a-b
            while l>0:
                p=p.next
                l-=1
            while p and q:
                if p==q:
                    return p
                else:
                    p=p.next
                    q=q.next
            return None
        else:
            l = b-a
            while l>0:
                q=q.next
                l-=1
            while p and q:
                if p==q:
                    return p
                else:
                    p=p.next
                    q=q.next
            return None
```
