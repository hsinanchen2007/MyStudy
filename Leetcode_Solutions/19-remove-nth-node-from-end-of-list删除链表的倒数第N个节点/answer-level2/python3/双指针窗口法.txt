### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        """
        思路：双指针窗口法，设置两个指针p和q，p和q之间间隔n个节点，然后循环将p和q指针向后移动，
        一旦q指针指向为空，那么p指针的下一个节点就是需要删除的节点。
        """
        assert n >= 0
        dummyNode = ListNode(0)
        dummyNode.next = head # 虚拟头节点的下一个节点为头结点
        p,q = dummyNode, dummyNode
        for i in range(n+1): # 将q指针后移n+1个位置，形成一个大小为n+2的窗口
            assert q
            q = q.next
        while q: # 将p和q指针向后移动，直到q指针指向链表尾部Null
            p = p.next
            q = q.next
        delNode = p.next # p指针指向的节点的下一个节点是需要被删除的节点
        p.next = delNode.next # p指针指向被删除节点的下一个节点
        del delNode # 删除节点
        return dummyNode.next # 返回原始的头结点
            
            
```