### 解题思路
和普通的删除重复节点的题不同，如果我们发现当前节点和当前节点的后几个节点相同，那么这几个节点都要删除，所以我们肯定是需要有两个指针的，为了保证出现重复元素的节点时，能够删除当前的节点。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        v_head = ListNode(0)
        v_head.next = head
        p = v_head
        q = head
        flag = 0 # 当前节点是否应该删除
        while q.next:
            if q.val == q.next.val:
                q.next = q.next.next
                flag = 1
            elif flag:
                p.next = q.next
                q = p.next
                flag = 0
            else:
                p = q
                q = q.next
        if flag:
            p.next = q.next
        return v_head.next

```