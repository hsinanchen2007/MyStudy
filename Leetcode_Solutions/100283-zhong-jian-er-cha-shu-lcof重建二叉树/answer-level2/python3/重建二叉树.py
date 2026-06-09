## 解题思路
**树的问题首先可以想到递归解决。**
每次递归要做的事情就是：找到根结点并连接左右子树的根结点。

Tips：
1. 前序遍历结果的第一个元素是根结点
2. 中序遍历结果里根结点前的元素是左子树，有N个；根结点后的元素是右子树，有M个
3. 那么前序遍历结果里根节点后N个元素是左子树前序遍历的结果，后M个元素是右子树前序遍历的结果。

时间复杂度：O(N)
空间复杂度：O(1)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None

        root = TreeNode(preorder[0])

        root_idx = inorder.index(preorder[0])

        root.left = self.buildTree(preorder[1:root_idx+1], inorder[:root_idx])
        root.right = self.buildTree(preorder[root_idx+1:], inorder[root_idx+1:])

        return root
```