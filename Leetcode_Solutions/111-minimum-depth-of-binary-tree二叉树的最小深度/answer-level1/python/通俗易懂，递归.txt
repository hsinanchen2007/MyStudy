### 解题思路
1、前序遍历
2、递归记录根节点到每个叶子节点的深度
3、设置全局变量的最小深度，每次比较替换最小值
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def search(node,num):
            if not node:
                return
            num = num +1
            if not node.left and not node.right:
                self.res = min(self.res,num)
            else:
                search(node.left,num)
                search(node.right,num)
        
        if root:
            self.res = float('inf')
            search(root,0)
            return self.res
        else:
            return 0
            


```