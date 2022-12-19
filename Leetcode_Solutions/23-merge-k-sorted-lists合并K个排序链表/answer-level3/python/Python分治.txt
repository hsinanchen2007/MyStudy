### 解题思路
分治的思想很简单，就是两两进行合并，直到将所有链表合并成一个，如果对两个链表的合并熟练的话这道题应该不难解决。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if lists == []:
            return None
        def get_res(lists):
            if len(lists) == 1:
                return lists
            if len(lists) == 2:
                p, q = lists[0], lists[1]
                v_head = ListNode(0)
                temp = v_head
                while p or q:
                    if p and (q is None or p.val < q.val):
                        temp.next = ListNode(p.val)
                        p = p.next
                    else:
                        temp.next = ListNode(q.val)
                        q = q.next
                    temp = temp.next
                return [v_head.next]
            mid = (len(lists) - 1) // 2
            return get_res(get_res(lists[:mid + 1]) + get_res(lists[mid + 1:]))
        return get_res(lists)[0]

```