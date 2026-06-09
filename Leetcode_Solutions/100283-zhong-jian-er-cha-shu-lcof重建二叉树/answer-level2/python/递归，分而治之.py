### 解题思路
首先,二叉树的先序遍历的遍历顺序是根左右，而中序遍历的顺序是左右根。
先序遍历的第一个结点值代表根结点值，我们可以根据这个值根据中序遍历来把二叉树划分为左右俩颗子树。
那么先序遍历的第二个结点值代表左子树的根结点，我们可以根据之前划分的左子树部分，找出在中序遍历中，该根结点的位置，继续划分，划分出左子树的左子树，以及左子树的右子树。
...
依次类推，直到无法继续划分位置。
### 代码
```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder.pop(0))
        divide = inorder.index(root.val)
        if divide > 0:
            root.left = self.buildTree(preorder, inorder[:divide])
        if divide < len(inorder) - 1:
            root.right = self.buildTree(preorder, inorder[divide+1:])
        return root
```
