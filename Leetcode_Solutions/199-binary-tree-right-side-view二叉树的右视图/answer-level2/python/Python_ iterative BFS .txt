### 解题思路
树的层级遍历用队列。我们用两个队列`q`和`s`轮流存储每一层的节点，然后记录每一层最后一个节点的数值，最后返回。

### 代码

```python3
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root: return []
        q, s = [root], []
        res = []
        while q:
            while q:
                node = q.pop(0)
                if not q: res.append(node.val)
                if node.left:
                    s.append(node.left)
                if node.right:
                    s.append(node.right)
            q, s = s, q
        return res 
```