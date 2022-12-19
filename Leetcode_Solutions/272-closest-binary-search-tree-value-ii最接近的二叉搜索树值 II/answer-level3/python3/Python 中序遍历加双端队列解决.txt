

```
'''
中序遍历二叉树，用双端队列维护k个最接近target的数值
'''

from collections import deque
from typing import Deque, List

class Solution:

    def dfs(self, root, que: Deque, target, k):
        if root is None:
            return

        self.dfs(root.left, que, target, k)

        if len(que) < k:
            que.append(root.val)
        else:
            dis = abs(root.val - target)
            dis1 = abs(que[0] - target)

            if dis < dis1:
                que.popleft()
                que.append(root.val)

        self.dfs(root.right, que, target, k)

    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        que = deque()
        self.dfs(root, que, target, k)
        return list(que)
```
