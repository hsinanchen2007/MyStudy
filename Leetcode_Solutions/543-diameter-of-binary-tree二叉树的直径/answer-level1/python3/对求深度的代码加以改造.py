### 解题思路
某个节点的答案，就是左孩子的深度加右孩子的深度
先写出来求深度的代码
然后在求深度的代码中，用左孩子深度加右孩子深度，就是这个节点的最大直径


不明白官方解法为什么要左右孩子深度之和加1，明明左右孩子加和就是结果

### 代码

```python3
class Solution:
    def depth(self, root: TreeNode):
        """
        求二叉树的深度
        """
        if not root:
            return 0
        left_depth = self.depth(root.left)
        right_depth = self.depth(root.right)
        # 左右深度节点数的和
        self.result = max(self.result, left_depth + right_depth)
        return max(left_depth, right_depth) + 1

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        # 默认是root的1个节点
        self.result = 0
        self.depth(root)
        return self.result
```