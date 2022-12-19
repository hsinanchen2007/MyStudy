## 思路:

思路一: 可以套用与 [133. 克隆图](https://leetcode-cn.com/problems/clone-graph/)|[题解链接](https://leetcode-cn.com/problems/clone-graph/solution/dfs-he-bfs-by-powcai)一样方法两种遍历(`DFS`, `BFS`)

思路二: 因为是链表,所以直接先把所有节点找到, 再连线;

思路三:

这个方法十分巧妙 , 用图说明吧

![1563690472002.png](https://pic.leetcode-cn.com/4bc12694524ee548153e207fd069607af8299530bb2a2f3690c68f7b86d91e2b-1563690472002.png)


## 代码:

思路一: `DFS` 和 `BFS`

```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        lookup = {}
        def dfs(head):
            if not head: return None
            if head in lookup: return lookup[head]
            clone = Node(head.val, None, None)
            lookup[head] = clone 
            clone.next, clone.random = dfs(head.next), dfs(head.random)
            return clone
        return dfs(head)
```



```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        from collections import deque
        lookup = {}
    
        def bfs(head):
            if not head: return head
            clone = Node(head.val, None, None)
            queue = deque()
            queue.appendleft(head)
            lookup[head] = clone
            while queue:
                tmp = queue.pop()
                if tmp.next and tmp.next not in lookup:
                    lookup[tmp.next] = Node(tmp.next.val, [], [])
                    queue.appendleft(tmp.next)  
                if tmp.random and tmp.random not in lookup:
                    lookup[tmp.random] = Node(tmp.random.val, [], [])
                    queue.appendleft(tmp.random)
                lookup[tmp].next = lookup.get(tmp.next)
                lookup[tmp].random = lookup.get(tmp.random)
            return clone
        return bfs(head)
```

思路二:

```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        lookup = {}
        node = head
        # 创建所有节点
        while node:
            lookup[node] = Node(node.val, None, None)
            node = node.next
        
        node = head
        # 节点连接
        while node:
            lookup[node].next = lookup.get(node.next)
            lookup[node].random = lookup.get(node.random)
            node = node.next
        return lookup[head]
```



```java []
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Map<Node, Node> lookup = new HashMap<>();
        Node node = head;
        while (node != null){
            lookup.put(node, new Node(node.val, null, null));
            node = node.next;
        }
        node = head;
        while (node != null){
            lookup.get(node).next = lookup.get(node.next);
            lookup.get(node).random = lookup.get(node.random);
            node = node.next;
        }
        return lookup.get(head);
    }
}
```

思路三:

```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        # 复制节点
        cur = head
        while cur:
            # 保存下一个节点
            tmp = cur.next
            # 后面跟着同样的节点
            cur.next = Node(cur.val, None, None)
            # 拼接
            cur.next.next = tmp
            cur = tmp
        # 复制random指针
        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        # 拆分
        cur = head
        copy_head = head.next
        copy_cur = copy_head
        while copy_cur.next:
            # 组head
            cur.next = cur.next.next
            cur = cur.next
            # 组 copy_head
            copy_cur.next = copy_cur.next.next
            copy_cur = copy_cur.next
        # 把链表结束置空
        cur.next = copy_cur.next
        copy_cur.next = None
        return copy_head
```



```java []
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        // 复制
        Node cur = head;
        while (cur != null) {
            Node tmp = cur.next;
            cur.next = new Node(cur.val, null, null );
            cur.next.next = tmp;
            cur = tmp;
        }
        // 置随机指针
        cur = head;
        while (cur != null) {
            if (cur.random != null) cur.next.random = cur.random.next;
            cur = cur.next.next;
        }
        // 拆分
        cur = head;
        Node copy_head = cur.next;
        Node copy_cur = copy_head;
        while (copy_cur.next != null) {
            cur.next = cur.next.next;
            cur = cur.next;

            copy_cur.next = copy_cur.next.next;
            copy_cur = copy_cur.next;
        }
        // 结束标志null
        cur.next = null;
        return copy_head;
    }
}
```

