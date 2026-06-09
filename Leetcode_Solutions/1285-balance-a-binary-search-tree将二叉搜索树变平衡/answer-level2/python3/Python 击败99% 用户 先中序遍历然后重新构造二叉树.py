![image.png](https://pic.leetcode-cn.com/e60cbb48b2d4191a900f0248afa5df5448b93f2c4b0196651f40dc6fd48cf803-image.png)


```
class Solution:

    def dfs(self, root: TreeNode, node_path):
        if root is None:
            return

        self.dfs(root.left, node_path)
        node_path.append(root)
        self.dfs(root.right, node_path)

        return node_path


    def build(self, node_path, start, end):
        if start == end:
            node_path[start].left = None
            node_path[start].right = None
            return node_path[start]
        elif start > end:
            return None

        mid = (start + end) // 2
        node_path[mid].left = self.build(node_path, start, mid-1)
        node_path[mid].right = self.build(node_path, mid+1, end)
        return node_path[mid]

    def balanceBST(self, root: TreeNode) -> TreeNode:
        mid_path = self.dfs(root, [])
        return self.build(mid_path, 0, len(mid_path)-1)
```
