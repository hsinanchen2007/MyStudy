递归拆解：
1、小问题：每一步都是左子树与右子树进行交换
2、对所有子树进行搜索遍历
2、递归结束条件：空值返回
```
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        
        if root:
            tmp = root.left
            root.left = root.right
            root.right = tmp
            self.invertTree(root.left)
            self.invertTree(root.right)
       
        return root
```
