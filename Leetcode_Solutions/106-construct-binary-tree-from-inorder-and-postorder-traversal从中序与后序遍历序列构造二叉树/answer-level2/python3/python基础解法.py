### 解题思路
与105题差不多思路，使用递归，出口条件就是当任意一个为空返回none，后序遍历根节点是最后一个元素，和前序遍历的区别，还有就是顺序不一样，其他的差不多

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
        if not inorder:
            return None
        root = TreeNode(postorder[-1])
        root_index = inorder.index(root.val)
        root.left = self.buildTree(inorder[:root_index], postorder[:root_index])
        root.right = self.buildTree(inorder[root_index+1:], postorder[root_index:len(postorder)-1])
        return root
```