### 解题思路
先写一个中序遍历算法把两棵树的元素都提取出来
然后直接暴力排序返回

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        root1List = self.inOrderTraversal(root1)
        root2List = self.inOrderTraversal(root2)
        res = root1List + root2List
        res.sort()
        return res
                
        
    def inOrderTraversal(self, root: TreeNode) -> list:
        if root == None:
            return []
        return self.inOrderTraversal(root.left) + [root.val] + self.inOrderTraversal(root.right)
```