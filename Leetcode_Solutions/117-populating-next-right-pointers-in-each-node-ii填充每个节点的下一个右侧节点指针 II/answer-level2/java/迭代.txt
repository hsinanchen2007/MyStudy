## 思路:

和[上一题](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/di-gui-he-die-dai-by-powcai-4)一样,可以用BFS做

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

但是题目要求我们用常数空间,我们借用上一题的迭代方法!

用`cur`记层该层访问节点

用`head`记录下一层合成链表的开头.

用`tail`记录下一层合成链表的结尾.

直接看代码, 就能理解了!

## 代码:

```python [1]
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        cur = root
        head = None
        tail = None
        while cur:
            while cur:
                if cur.left:
                    if not head:
                        head = cur.left
                        tail = cur.left
                    else:
                        tail.next = cur.left
                        tail = tail.next
                if cur.right:
                    if not head:
                        head = cur.right
                        tail = cur.right
                    else:
                        tail.next = cur.right
                        tail = tail.next
                cur = cur.next
            cur = head
            head = None
            tail = None
        return root
```



```java [1]
class Solution {
    public Node connect(Node root) {
        Node cur = root;
        Node head = null;
        Node tail = null;
        while (cur != null) {
            while (cur != null) {
                if (cur.left != null) {
                    if (head == null) {
                        head = cur.left;
                        tail = head;
                    } else {
                        tail.next = cur.left;
                        tail = tail.next;
                    }
                }
                if (cur.right != null) {
                    if (head == null) {
                        head = cur.right;
                        tail = head;
                    } else {
                        tail.next = cur.right;
                        tail = tail.next;
                    }
                }
                cur = cur.next;
            }
            cur = head;
            head = null;
            tail = null;
        }
        return root;
    }
}
```

