![image.png](https://pic.leetcode-cn.com/04d6a4759339c47b633044808c7310ef4aa2ae494520ffc5241f40b4904e21e6-image.png)


```
class Solution:

    def getNodeNum(self, root: TreeNode):
        if root is None:
            return 0
        return self.getNodeNum(root.left) + self.getNodeNum(root.right) + 1

    def getNode(self, root: TreeNode, x: int):
        if root is None:
            return None

        if root.val == x:
            return root

        ret = self.getNode(root.left, x)
        return ret if ret is not None else self.getNode(root.right, x)

    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        if x == root.val:
            min_sub_tree_num = min(self.getNodeNum(root.left), self.getNodeNum(root.right))
            return  min_sub_tree_num + 1 < n // 2 + 1
        else:
            node1 = self.getNode(root, x)

            if self.getNodeNum(node1) < n // 2 + 1:
                return True
            return max(self.getNodeNum(node1.left), self.getNodeNum(node1.right)) +1 >= n // 2 + 1
```
