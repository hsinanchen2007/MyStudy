按深度优先遍历树，如果走到了叶子结点，将当前的完整路径进行保存即可

```
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root:
            return []
        self.res = []
        self.dfs([], root)
        self.res = ['->'.join([str(i) for i in item]) for item in self.res]
        print('res:', self.res)
        return self.res
    
    def dfs(self, path, root):
        if not root.left and not root.right: # 如果到达了叶子结点
            print('path:', path + [root.val,])
            self.res.append(path + [root.val,])
            return

        if root.left:
            self.dfs(path+[root.val, ], root.left)
        if root.right:
            self.dfs(path+[root.val, ], root.right)
```