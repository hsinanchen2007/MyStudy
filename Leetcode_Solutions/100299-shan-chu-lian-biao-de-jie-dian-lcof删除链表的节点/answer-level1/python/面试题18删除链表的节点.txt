### 解题思路
通过设置两个节点`node and node.next`,在遍历节点的过程中，如果发现`node.next.val == val`,则令`node.next = node.next.next`.

### 代码

```python3
class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head.val == val: return head.next # 特殊情况:位于首部，返回head.next
        node=head
        while node and node.next:#
            if node.next.val == val:   # 找到了要删除的结点，删除
                node.next = node.next.next
            node = node.next
        return head

```