### 解题思路
栈保存当前层节点信息
当前层无节点退出

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        stack = [root]
        result = []
        while stack:
            tmp = []
            tmp_l_r = []
            for node in stack:
                tmp.append(node.val)
                if node.left:
                    tmp_l_r.append(node.left)
                if node.right:
                    tmp_l_r.append(node.right)
            result.append(tmp)
            stack = tmp_l_r
        
        return result

        
            
            
```