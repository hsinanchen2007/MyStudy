### 解题思路
- 遍历链表，使用列表recList记录链表元素；
 若当前元素位于列表recList中，即已存在，则删除当前节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        recList = []
        rNode = head
        while head:
            if head.val not in recList:
                recList.append(head.val)
                prevNode = head
                head = head.next
            else:
                nextNode = head.next
                prevNode.next = nextNode
                head.next = None
                head = nextNode

        return rNode

```

### 执行结果
执行用时: 44 ms, 在所有 python3 提交中击败了89.39%的用户
内存消耗: 12.8 MB, 在所有 python3 提交中击败了99.44%的用户