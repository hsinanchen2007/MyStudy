### 解题思路
1.不会的话可以画图来理解会好很多
2.`关键是找到中序序列中的前序的首元素的索引，然后对root的左子树和右子树进行遍历`
3.`最后返回root即可`

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        if len(preorder) == 1:
            #返回的是节点信息
            return TreeNode(preorder[0])
        root = TreeNode(preorder[0])
        #从中序遍历中找到前序的首元素
        pos = inorder.index(preorder[0])
        #递归遍历左子树
        root.left = self.buildTree(preorder[1:pos+1],inorder[:pos])
        #递归遍历右子树
        root.right = self.buildTree(preorder[pos+1:],inorder[pos+1:])
        return root
```