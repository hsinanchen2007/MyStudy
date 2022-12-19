### 解题思路
遍历2次，字典存储。

### 代码

```python3
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        hashmap = {}
        cur = head
        while cur:
            hashmap[cur] = Node(cur.val)
            cur = cur.next
        hashmap[None] = None
        cur = head
        while cur:
            hashmap[cur].next = hashmap[cur.next]
            hashmap[cur].random = hashmap[cur.random]
            cur = cur.next
        return hashmap[head]
```