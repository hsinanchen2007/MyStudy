### 解题思路
前序遍历+字典判别

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return False
        res={}#定义一个字典，用来存储遍历的结果，key值存放node.val ,value可以存放出现次数，用于更加负责的题目，这个题的value 
        def inorderTraversal(node):
            if not node:
                return
            #res[node.val]=res.get(node.val,0)+1
            res[node.val]=1
            inorderTraversal(node.left)
            inorderTraversal(node.right)
        inorderTraversal(root)
        return len(res)==1 #如果字典的key的数量等于1，则说明是单值
```