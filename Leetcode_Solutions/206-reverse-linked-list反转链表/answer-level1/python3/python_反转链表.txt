### 解题思路
方法一：迭代（循环）
构造辅助结点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        preNode=None
        while head:
            postNode=head.next
            head.next=preNode
            preNode=head
            head=postNode
        return preNode
```

### 解题思路
方法二：
递归
劝退，官方思路非常棒，我也是学习者之一
我倒在了判断语句上，短短一句话折腾了好久

### 代码
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        end=self.reverseList(head.next)
        head.next.next=head
        head.next=None
        return end
```