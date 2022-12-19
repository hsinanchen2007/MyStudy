### 解题思路
菜鸡的两个思路：第一种简单递归，第二种把链表元素放入list中，返回逆序list

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head:
            return self.reversePrint(head.next) + [head.val]
        else:
            return []


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head is None:
            return []
        else:
            res = []
            while head:
                res.append(head.val)
                head = head.next
            return res[::-1]
```

```