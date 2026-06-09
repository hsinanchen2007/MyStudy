### 解题思路
如果删除的是头结点 直接返回头结点的next
定义双指针 头指针的下一个开始遍历
如果当前对象存在 且 不是要删除的对象 继续往后遍历
一直到找到要删除的那个结点 直接把上一个结点的next 指向 下一个结点的next

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        # 如果删除的是头结点 直接返回头结点的next
        if head.val == val: 
            return head.next
        # 定义双指针 
        pre, cur = head, head.next
        # 如果当前对象存在 且 不是要删除的对象 继续往后遍历
        while cur and cur.val != val:
            pre, cur = cur, cur.next
        # 一直到找到要删除的那个结点 直接把上一个结点的next 指向 下一个结点的next
        pre.next = cur.next
        return head


```