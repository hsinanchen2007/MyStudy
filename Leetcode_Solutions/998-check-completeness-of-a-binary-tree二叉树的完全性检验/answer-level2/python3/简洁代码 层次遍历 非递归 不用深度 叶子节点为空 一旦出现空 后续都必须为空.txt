很简单的想法，层次遍历，用队列，叶子节点都入队（无论是否空）。

一旦出现空 后续都必须为空。

```
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        """层次遍历时，叶子节点为空。一但出现空，那么后续的值都必须时空。"""
        q = [root]
        has_none = False # 是否出现过空
        while q:
            p = q.pop(0) # 出队
            if not has_none and not p: # 第一次出现空
                has_none = True
            elif has_none and p: # 空后面出现了非空
                return False
            if p: # 子节点入队列，无论是否空
                q.extend([p.left, p.right])
        return True
```
