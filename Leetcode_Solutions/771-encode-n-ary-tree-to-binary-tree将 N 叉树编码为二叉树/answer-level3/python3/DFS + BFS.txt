## 思路:

可以把N叉树一个节点的第一个孩子都作为二叉树的左节点，然后该节点兄弟挂载在第一个孩子的右节点上。

如图所示：

![image-20200229160301999.png](https://pic.leetcode-cn.com/3c6fe6a29bac6f6f14a7c15df8d4fefa3b31850e3b7accf72353e4c920158da4-image-20200229160301999.png)


树有两种遍历方式：

思路一：DFS

思路二：BFS

## 代码:

思路一：DFS

```python
class Codec:

    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Node') -> TreeNode:
        if not root: return
        res = TreeNode(root.val)
        if root.children:
            res.left = self.encode(root.children[0])
        cur = res.left
        for node in root.children[1:]:
            cur.right = self.encode(node)
            cur = cur.right
        return res

    # Decodes your binary tree to an n-ary tree.
    def decode(self, data: TreeNode) -> 'Node':
        if not data: return
        res = Node(data.val, [])
        cur = data.left
        while cur:
            res.children.append(self.decode(cur))
            cur = cur.right
        return res
```

思路二：BFS

```python
class Codec:

    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Node') -> TreeNode:
        from collections import deque
        if not root: return
        new_TreeNode = TreeNode(root.val)
        queue = deque([[new_TreeNode, root]])

        while queue:
            cur_TreeNode, cur_Node = queue.pop()
            if not cur_Node.children: continue
            # 先把第一个孩子放在树左边
            cur_TreeNode.left = TreeNode(cur_Node.children[0].val)
            # 入队列
            queue.appendleft([cur_TreeNode.left, cur_Node.children[0]])
            # 把右边挂兄弟
            cur_TreeNode = cur_TreeNode.left
            for node in cur_Node.children[1:]:
                new_node = TreeNode(node.val)
                cur_TreeNode.right = new_node
                cur_TreeNode = cur_TreeNode.right
                queue.appendleft([new_node, node])
        return new_TreeNode
```

