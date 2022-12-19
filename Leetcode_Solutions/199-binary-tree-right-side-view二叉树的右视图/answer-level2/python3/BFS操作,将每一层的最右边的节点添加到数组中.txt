### 解题思路
相同类型题目102,107, 103
### 代码

```python3
from collections import deque
class Solution:
    def rightSideView(self, root: TreeNode) -> [int]:
        res = []
        if not root:
            return res
        queue = deque([root])  # 储存每一层节点的队列
        level = 0  # 表示节点的层级

        while queue:
            res.append(queue[-1].val)
            for i in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            level += 1        
        return res
```