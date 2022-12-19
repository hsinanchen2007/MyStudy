直接基于栈实现中序遍历，保存上一个节点pre，头节点head和尾节点tail，对于当前节点cur有上一节点的right指向当前节点cur，当前节点cur的left指向pre。

```
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        head = None
        pre = None
        tail = None

        stack = []
        cur = root

        while stack or cur:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                node = stack.pop()
                if not head:
                    head = node
                    pre = node
                else:
                    pre.right = node
                    node.left = pre
                    pre = node
                tail = node
                cur = node.right
        
        head.left = tail
        tail.right = head
        return head
```
