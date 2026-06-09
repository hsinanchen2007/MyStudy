### 解题思路
- 维护一个history列表，用于存储见过的数字；
- 维护两个指针cur,rear:cur用于遍历链表，rear指向已经检查并跳过重复元素的链表的尾部。
- 每次检查cur.val是不是在history里，在的话就查看下一个；
- 如果不在history里，则rear.next指向新元素（越过所有重复元素），紧接着rear指向新元素（即当前链尾）
- 返回之前要将rear.next指向None；（rear后面可能全是重复元素，rear一直未移动，rear.next恰是重复元素）

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head: return head 
        history = [head.val]
        cur = head
        rear = head
        while cur:
            if cur.val not in history:
                history.append(cur.val)
                rear.next = cur
                rear = rear.next
                cur = cur.next
            else:
                cur = cur.next
        rear.next = None
        return head
```