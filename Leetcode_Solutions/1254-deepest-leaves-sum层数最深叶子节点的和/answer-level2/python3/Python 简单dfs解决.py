![image.png](https://pic.leetcode-cn.com/ee5f02f2d70a940cfe706fa8c7329a6d415ca2864f04d175882bc500f225b9ed-image.png)


```
'''
dfs 遍历，统计每一个层数的节点即可
'''

class Solution:
    def dfs(self, root, dep2nodes, dep):
        if root is None:
            return

        if dep not in dep2nodes:
            dep2nodes[dep] = []
        dep2nodes[dep].append(root.val)

        self.dfs(root.left, dep2nodes, dep+1)
        self.dfs(root.right, dep2nodes, dep+1)

    def deepestLeavesSum(self, root: TreeNode) -> int:
        dep2nodes = {}
        self.dfs(root, dep2nodes, 0)
        return sum(dep2nodes[max(dep2nodes.keys())])
```
