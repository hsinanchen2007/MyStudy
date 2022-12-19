### 解题思路
1.遍历出所有节点到队列
2.倒序遍历队列
3.currNode.next = nextNode
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        res = []
        while head:
            res.append(head)
            head = head.next
        if not res:return None
        res[0].next = None
        for i in range(len(res)-1,0,-1):
            res[i].next = res[i-1]
        return res[len(res)-1]

```