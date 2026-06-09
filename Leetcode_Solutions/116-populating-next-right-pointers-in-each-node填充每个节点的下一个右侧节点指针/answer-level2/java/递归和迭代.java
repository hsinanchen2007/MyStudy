## 思路:

与下一题[117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)都可以用`BFS`方法,如下:

```python
def connect(self, root: 'Node') -> 'Node':
        from collections import deque
        if not root: return root
        queue = deque()
        queue.appendleft(root)
        while queue:
            p = None
            n = len(queue)
            for _ in range(n):
                tmp = queue.pop()
                if p:
                    p.next = tmp
                    p = p.next
                else:
                    p = tmp
                if tmp.left:
                    queue.appendleft(tmp.left)
                if tmp.right:
                    queue.appendleft(tmp.right)
            p.next = None 
        return root
```

但是不符合题意, 要使用常量级额外空间

所以我们用其他空间$O(1)$的方法

思路一: 递归

思路二: 迭代

## 代码:

思路一:

```python [1]
def connect(self, root: 'Node') -> 'Node':
        if not root:
            return 
        if root.left:
            root.left.next = root.right
            if root.next:
                root.right.next = root.next.left
        self.connect(root.left)
        self.connect(root.right)
        return root
```



```java [1]
class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        if (root.left != null) {
            root.left.next = root.right;
            if (root.next != null) root.right.next = root.next.left;
        }
        connect(root.left);
        connect(root.right);
        return root;
    }
}
```

思路二:

```python [2]
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        pre = root
        while pre:
            cur = pre
            while cur:
                if cur.left: cur.left.next = cur.right
                if cur.right and cur.next: cur.right.next = cur.next.left
                cur = cur.next
            pre = pre.left
        return root
```



```java [2]
class Solution {
    public Node connect(Node root) {
        Node pre = root;
        while (pre != null) {
            Node cur = pre;
            while (cur != null) {
                if (cur.left != null) cur.left.next = cur.right;
                if (cur.right != null && cur.next != null) cur.right.next = cur.next.left;
                cur = cur.next;
            }
            pre = pre.left;
        }
        return root;
    }
}
```

