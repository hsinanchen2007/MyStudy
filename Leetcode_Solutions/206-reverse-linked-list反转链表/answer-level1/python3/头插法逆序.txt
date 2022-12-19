### 解题思路
采用头插法的方式，
其中temp先保存head中已经逆序过的内容，
p 指向即将需要逆序的结点
p 不断向后查找直到空
[https://www.cnblogs.com/Halo-zyh-Go/p/12363058.html]()
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p = head
        head = None
        temp = ListNode(0)
        while p:
            temp = head
            head = p
            p = p.next
            head.next = temp
        return head
```