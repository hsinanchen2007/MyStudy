### 解题思路
首先用一个队列queue辅助，层次遍历二叉树，并记录节点所在的层次
用res字典顺序记录每一个层次的节点
正序遍历res，每个一层做一次列表反转

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
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
        ans = []
        k = 0
        for i in res:
            if k%2==0:
                ans.append(res[i])
            else:
                res[i].reverse()
                ans.append(res[i])
            k += 1
        return ans
```