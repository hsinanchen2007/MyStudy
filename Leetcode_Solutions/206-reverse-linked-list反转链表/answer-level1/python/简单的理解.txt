### 解题思路
迭代法：看似很简单的题目，其实精简的代码里面有很多玄机
- pre指针：始终都指向逆转链表的最后一个
- cur指针：始终指向呆逆转链表的第一个
- dummy指针：始终在头部，也是最终需要返回的头节点
- 每次的操作：
  - 将cur结点后边的待翻转链表接到pre上
  - 将cur拿到dummy 前面
  - 重新调整dummy
  - 调整cur

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        
        dummy = head
        pre = head
        cur = head.next
        while cur:
            pre.next = cur.next
            cur.next = dummy
            dummy = cur
            cur = pre.next
        
        return dummy

        
```