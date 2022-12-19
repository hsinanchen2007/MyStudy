### 解题思路
使用tmp作为广度遍历的辅助列表。每次遍历的时候，将当前层数加入到队列中，每次出队列是，就可以知道当前值属于哪一层

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        que = []
        res = []
        floor = 1
        curr = 1
        que.append((root,floor))
        tmp = []
        while que:
            p,f = que.pop(0)
            if f == curr:
                tmp.append(p.val)
            else:
                res.append(tmp)
                tmp = []
                curr = f
                tmp.append(p.val)
            if p.left:
                que.append((p.left,f+1))
            if p.right:
                que.append((p.right, f+1))
        if tmp:
            res.append(tmp)
        return res
```