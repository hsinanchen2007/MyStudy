### 解题思路
链表二分法分割，利用归并排序方式合并

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        # 同样的，首先考虑特殊情况
        if not head or not head.next: return head # termination.
        # 快慢指针找到中间节点
        slow, fast = head, head.next
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
        mid, slow.next = slow.next, None # save and cut.

        # 递归分割链表
        left, right = self.sortList(head), self.sortList(mid)

        # 归并排序两个子链表 left right并把他们合并：
        h = res = ListNode(0)
        while left and right:
            if left.val < right.val:
                h.next, left = left, left.next
            else:
                h.next, right = right, right.next
            h = h.next
        
        h.next = left if left else right 

        return res.next


        
        
        
        

```