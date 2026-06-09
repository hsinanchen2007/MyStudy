### 递归
执行用时 :44 ms, 在所有Python3提交中击败了95.65%的用户

内存消耗 :13 MB, 在所有Python3提交中击败了87.42%的用户

思路：交换左右子树的值，再递归左右子树。

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return 
        else:
            root.left, root.right = root.right, root.left
            root.left = self.invertTree(root.left)
            root.right = self.invertTree(root.right)
        return root
```
#### 复杂度分析
##### 时间复杂度：
每个结点只访问一次，O(n)
##### 空间复杂度：
树完全不平衡（只有左子树），递归调用n次，因此复杂度为O(n);若树是平衡的，则递归调用logn(*2)次，复杂度为O(log(n))
