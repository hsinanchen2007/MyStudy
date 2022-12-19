### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans=[]#开辟新的数组
        if not root:
            return []
        def ansTraverse(node):#声明一个新的函数
            if not node:#遇到空节点，返回，这是关键
               return
            ans.append(node.val)#先将结果添加至数组
            ansTraverse(node.left)#递归遍历左子树
            ansTraverse(node.right)#递归遍历右子树
        ansTraverse(root)#调用新的函数
        return ans#返回结果数组
```