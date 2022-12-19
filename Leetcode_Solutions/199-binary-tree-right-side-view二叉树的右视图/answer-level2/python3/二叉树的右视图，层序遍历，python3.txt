### 解题思路
返回二叉树层序遍历结果中每一层的最后一个元素

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        queue = [[root, 1]]
        res = {1:[root.val]}
        i = 0
        while i < len(queue):
            if queue[i][0].left:
                queue.append([queue[i][0].left, queue[i][1]+1])
                res.setdefault(queue[i][1]+1, []).append(queue[i][0].left.val)
            if queue[i][0].right:
                queue.append([queue[i][0].right, queue[i][1]+1])
                res.setdefault(queue[i][1]+1, []).append(queue[i][0].right.val)
            i += 1
        return [res[i][-1] for i in res]
```