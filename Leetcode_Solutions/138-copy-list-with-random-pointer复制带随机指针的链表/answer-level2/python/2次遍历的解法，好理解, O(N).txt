2次遍历，一次创建新节点并连起来，第二次单独处理random

### 代码

```python
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """

        if not head: return None

        dic = {}
        root = Node(head.val)

        s = head
        t = root

        dic[s] = t

        while s.next:
            s = s.next
            t.next = Node(s.val)
            t = t.next
            dic[s] = t


        s = head
        t = root
        while s:
            if s.random:
                t.random = dic[s.random]
            s = s.next
            t = t.next


        return root
```