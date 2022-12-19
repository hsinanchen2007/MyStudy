### 解题思路
设置了一个前置链表来帮助建立双向链表，两种写法，一种是遍历过程中直接建链表，最省事，第二种是直接修改原链表，理论上更省内存，都一样快。

### 代码

```python []
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head: 
            return None
        ans = prev = Node(None, None, None, None)
        def f(node):
            if node:
                nonlocal prev
                prev.next = Node(node.val, prev, None, None)
                prev = prev.next
                f(node.child)
                f(node.next)
        f(head)
        ans.next.prev = None
        return ans.next
```
```python []
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head: 
            return None
        ans = prev = Node(None, None, None, None)
        def f(node):
            if node:
                nonlocal prev
                node.prev = prev
                prev = node
                f(node.child)
                node.child = None
                f(node.next)
        f(head)
        while prev.prev:
            prev.prev.next = prev
            prev = prev.prev
        ans.next.prev = None
        return ans.next
```


![image.png](https://pic.leetcode-cn.com/db8b7a9576a8952558cd0005516194978a037a5fc7b1b4623ca17c7f6ef81a3c-image.png)
![image.png](https://pic.leetcode-cn.com/5a744f72094747a3ab66f02fcbf0b65482ce84d80721821928770dcb5a236233-image.png)
