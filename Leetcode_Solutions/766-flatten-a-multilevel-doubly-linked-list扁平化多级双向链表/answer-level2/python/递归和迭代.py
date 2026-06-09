## 思路:

思路一：非递归

思路二：递归

## 代码:

非递归

```python
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head: return 
        dummy = Node(-1, None, None, None)
        p = dummy
        stack = [head]
        tail = p
        while stack:
            cur = stack.pop()
            # 建立链接
            tail.next = cur
            cur.prev = tail
            if cur.next:
                stack.append(cur.next)
            if cur.child:
                stack.append(cur.child)
            # 让孩子节点为空
            cur.child = None
            # 记录尾节点
            tail = cur
        p.next.prev = None
        return p.next
```

递归

```python
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head: return 
        dummy = Node(-1, None, None, None)
        p = dummy

        def dfs(pre, head):
            if not head:
                return pre
            head.prev = pre
            pre.next = head
            # 记录下一个节点
            tmpNext = head.next
            # 返回尾节点
            tail = dfs(head, head.child)
            head.child = None
            return dfs(tail, tmpNext)
            
        dfs(dummy, head)
        p.next.prev = None
        return p.next
```


