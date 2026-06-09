**思路：**

深度优先搜索，在搜索的过程中检查当前结点是否需要删去，如果结点不需要删除，而它的父结点被删除，那么将它加入答案数组里。一遍DFS把所有操作做完，需要一些编程技巧，我们可以先从两遍DFS入手，第一遍先标记需要加入答案数组的结点，即该结点不需要删除，而该结点的父结点需要删除，第二遍遍历答案数组，将答案数组中每棵树中需要删除的结点删除。然后我们可以考虑一遍DFS：如果当前结点是要被删除的，那么向上返回`None`，如果不需要被删除，则返回原结点，上层遍历左子树和右子树后，直接赋给这个返回值。还有一个优化就是把`to_delete`这个列表转换成集合，增加查询速度。


**代码：**
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 两遍DFS
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        if not root:
            return []
        self.ans = []
        
        def dfs(root, fd):
            if not root:
                return
            if root.val in to_delete:
                dfs(root.left, True)
                dfs(root.right, True)
            else:
                if fd:
                    self.ans.append(root)
                dfs(root.left, False)
                dfs(root.right, False)
            return
        
        def dfs_del(root):
            if not root:
                return
            if root.left and root.left.val in to_delete:
                root.left = None
            else:
                dfs_del(root.left)
            if root.right and root.right.val in to_delete:
                root.right = None
            else:
                dfs_del(root.right)
            return
        
        dfs(root, True)
        for node in self.ans:
            dfs_del(node)
        return self.ans
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 优化后的一遍DFS
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        s = set(to_delete)
        ans = []

        def dfs(root, flg):
            if not root: return None
            deleted = root.val in s
            if flg and not deleted:
                ans.append(root)
            root.left = dfs(root.left, deleted)
            root.right = dfs(root.right, deleted)
            return None if deleted else root
        dfs(root, True)
        return ans
```
