### 解题思路
此处撰写解题思路
考点：
1. 一定要看清题目，我开始没看清，当做无序链表去处理了
2. 有序链表删除重复元素，遇到重复元素，将当前节点的next指向删除节点的next即可
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        tmp = head
        while tmp != None and tmp.next != None:
            if tmp.val == tmp.next.val:
                tmp.next = tmp.next.next
            else:
                tmp = tmp.next
        return head
```