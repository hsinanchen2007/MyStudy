### 解题思路
递归，记录深度，并将同层节点放到同一个数组中。
稍加修改就可以应用在 32-II 以及 32-III. 都是对 `trees` 结构的变形。

### 代码

```python3
from typing import List
from functools import reduce
from operator import iconcat


class Solution:
    def levelOrder(self, root: TreeNode) -> List:
        """
        递归，记录深度，并将同层节点放到同一个数组中
        """
        trees = []
        self.levelOrderWithDepth(root, 0, trees)
        return reduce(iconcat, trees, [])

    def levelOrderWithDepth(self, root: TreeNode, depth: int, trees: [[int]]):
        if root is None or root.val is None or depth < 0:
            return
        while len(trees) <= depth:
            trees.append([])
        trees[depth].append(root.val)
        self.levelOrderWithDepth(root.left, depth + 1, trees)
        self.levelOrderWithDepth(root.right, depth + 1, trees)
```