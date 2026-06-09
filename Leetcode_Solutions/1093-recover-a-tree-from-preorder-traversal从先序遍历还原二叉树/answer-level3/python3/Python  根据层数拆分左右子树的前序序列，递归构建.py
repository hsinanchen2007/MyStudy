![image.png](https://pic.leetcode-cn.com/f6eb79add6db06a209aea41f40216100ed4060a86656e46056bcb2ad1fda3823-image.png)


```
import re
from pprint import pprint
from typing import List
class Solution:

    def buildTree(self, nodes: List[List[int]]) -> TreeNode:
        if len(nodes) == 0:
            return None

        root = TreeNode(nodes[0][1])
        if len(nodes) == 1:
            return root

        cur_layer = nodes[0][0]
        pos = []
        for i in range(1, len(nodes)):
            if nodes[i][0] == cur_layer + 1:
                pos.append(i)

        # 根据当前构建的子树的根的层数，去找下一层的两个子树的根的位置
        if len(pos) == 1:
            root.left = self.buildTree(nodes[pos[0]:])
        elif len(pos) == 2:
            root.left = self.buildTree(nodes[pos[0]: pos[1]])
            root.right = self.buildTree(nodes[pos[1]:])
        return root

    def recoverFromPreorder(self, S: str) -> TreeNode:
        vals = [int(s) for s in re.split(r'-+', S)]
        layer = [len(s) for s in re.split(r'[0-9]+', S)]

        nodes = []      # (层数，数值)
        for i, val in enumerate(vals):
            nodes.append([layer[i], val])

        return self.buildTree(nodes)
```
