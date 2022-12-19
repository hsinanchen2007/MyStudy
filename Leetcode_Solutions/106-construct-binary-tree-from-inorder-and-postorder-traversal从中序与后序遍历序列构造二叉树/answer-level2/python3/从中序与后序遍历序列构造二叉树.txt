### 解题思路
我的思路：
从105题中得到的启发,终于也是自己独立完成的一道...递归代码简单但是时间效率不高.(why:因为python list的index操作的时间复杂度为o(n),外层是递归遍历也是o(n),因此时间复杂度o(n^2))
若想提高时间效率,则可用哈希来存储进行查找,时间复杂度可降为o(n)

复杂度分析：                                                             
	• 时间复杂度：o(n^2)
	• 空间复杂度：o(n)

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
        if not postorder:
            return None
        root_val = postorder[-1]
        root = TreeNode(root_val)
        index = inorder.index(root_val)
        root.left = self.buildTree(inorder[:index],postorder[:index])
        root.right = self.buildTree(inorder[index+1:],postorder[index:-1])
        return root
```