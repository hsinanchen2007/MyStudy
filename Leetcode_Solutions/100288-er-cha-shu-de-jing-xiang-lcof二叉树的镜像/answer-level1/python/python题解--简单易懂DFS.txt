### 解题思路
![image.png](https://pic.leetcode-cn.com/2e9836b5b23b08972a5395502c6de3b5ded4fe3c09a64345d933ae94cf9e7456-image.png)
- 直接DFS即可,每次遍历都是对左右子树整体的交换,注意要把空指针考虑进来就可以了

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mirrorTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        root.left, root.right = root.right, root.left
        self.mirrorTree(root.left)
        self.mirrorTree(root.right)
        return root
```