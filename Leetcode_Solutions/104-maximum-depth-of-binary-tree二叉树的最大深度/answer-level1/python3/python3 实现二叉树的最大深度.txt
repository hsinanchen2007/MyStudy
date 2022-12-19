### 解题思路
这题的思路与【二叉树的所有路径】的思路差不多，只不过这题要多出一步，即计算出所有路径里最长的那一个。
1. 首先定义一个辅助函数DFS(self, root, path)，用来找出二叉树的所有路径；
     **·** 若当前节点的左孩子和右孩子均为空，说明已经走到叶子节点，直接将当前节点的路径path添加进result即可
     **·** 若当前节点的左孩子非空，递归时path需要加上左孩子节点的值 path + [root.left.val]
     **·** 若当前节点的右孩子非空，递归时path需要加上右孩子节点的值 path + [root.right.val]
2. 回到原函数，首先判空，若树为空，最大深度为0，直接返回0即可；
     **·** 调用DFS函数得到该二叉树的所有路径
     **·** 遍历存有所有路径的数组result，将所有路径的长度添加进新数组res，最后返回max(res)，即可得到二叉树的最大深度。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        self.result = []
        if not root:
            return 0
        self.DFS(root, [root.val])
        res = []
        for li in self.result:
            res.append(len(li))
        return max(res)
    
    def DFS(self, root, path):
        if not root.left and not root.right:
            self.result.append(path)
        if root.left:
            self.DFS(root.left, path + [root.left.val])
        if root.right:
            self.DFS(root.right, path + [root.right.val])
```