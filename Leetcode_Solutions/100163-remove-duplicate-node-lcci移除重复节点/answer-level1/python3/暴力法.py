### 解题思路
此题重复的是val，不是node,从题中不好判断，略坑，将第一次出现的val放入set，重复的删去，注意可能出现连续重复，所以不能直接跳到下个节点，需要这个节点再次检测next.val。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:
            return head
        res = ListNode(0)
        res.next = head
        nodes = set()
        head = res
        while head and head.next:
            if head.next.val in nodes:
                head.next = head.next.next
            else:
                nodes.add(head.next.val)
                head = head.next
        
        return res.next
```