![image.png](https://pic.leetcode-cn.com/57c487f65b99adbf5927d8c5e4e026df87e15cd4237d860ac9ee64128ee51d23-image.png)


```
'''
dfs 递归删除节点
'''

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if root is None:
            return None

        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)

        if root.left is None and root.right is None and root.val == target:
            return None
        return root
```
