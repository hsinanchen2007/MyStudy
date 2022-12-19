### 解题思路
先将链表head转化成列表res(方便用索引查找和截取数据)
截取res的中间节点作为根节点root，设中间节点的索引为mid
则`root.left = method(L[:mid])`, `root.right = method(L[mid+1:])`

返回root


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if not head:
            return
        res = []
        while head:
            res.append(head.val)
            head = head.next
        def method(L):
            if not L:
                return
            mid = len(L)//2
            root = TreeNode(L[mid])
            root.left = method(L[:mid])
            if mid+1 < len(L):
                root.right = method(L[mid+1:])
            return root
        return method(res)
```