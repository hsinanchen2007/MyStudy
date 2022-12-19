### 解题思路
此题和【从前序和中序遍历序列构造二叉树】的思路一样：
1. 先找到根节点的值。已知后序遍历的规则是“左右根”，最后一个节点即为根节点，所以root = TreeNode(postorder[-1])即可得到根节点。
2. 然后由根节点的值找到根节点在中序遍历序列中所处的位置 mid = inorder.index(postorder[-1])，以此可以将左子树和右子树分开。使用index函数找到该位置mid。
3. 然后就是递归还原左子树和右子树，此处的列表切片需要注意，要分别找到中序遍历和后序遍历序列中的左子树，中序遍历和后序遍历序列中的右子树。
4. 最后返回根节点即代表了整个构造好的二叉树。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        n = len(postorder)
        if n == 0:
            return None
        root = TreeNode(postorder[-1])
        mid = inorder.index(postorder[-1])
        
        root.left = self.buildTree(inorder[:mid], postorder[:mid])
        root.right = self.buildTree(inorder[mid+1:], postorder[mid:n-1])
        return root
```