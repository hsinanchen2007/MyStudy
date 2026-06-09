### 解题思路
首先，我们将根节点加入到队列中，我们每次弹出队首的结点，加入到结果中，并将结点的左右子节点加入到队尾。

### 代码

```python []
from collections import deque
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        levels = []
        level = 0
        if not root: return []
        queue = deque([root,])
        while queue:
            levels.append([])
            len_level = len(queue)
            for _ in range(len_level):
                node = queue.popleft()  # 出队
                levels[level].append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            level += 1
        return levels
```
### 复杂度分析

- 时间复杂度：$O(N)$，因为每个节点恰好会被运算一次。
- 空间复杂度：$O(N)$，保存输出结果的数组包含 N 个节点的值。