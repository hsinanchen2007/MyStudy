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
    def deleteNode(self, root, key): #在以当前节点为根的子树中删除一个节点
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        def successor(root): #准确来讲，这个函数是指当当前探索的节点有右子树的时候，返回右子树的最小节点的值
            """
            One step right and then always left
            """
            root = root.right
            while root.left:
                root = root.left
            return root.val
        
        def predecessor(root): #准确来讲，这个函数是指当当前探索的节点有左子树的时候，返回左子树的最小节点的值
            """
            One step left and then always right
            """
            root = root.left
            while root.right:
                root = root.right
            return root.val

        if not root:
            return None
        
        # delete from the right subtree
        if key > root.val: #在当前节点的右子树中删除一个节点，返回的是修改之后的右子树的根节点，与root.right相连
            root.right = self.deleteNode(root.right, key)
        # delete from the left subtree
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        # delete the current node
        else:
            # the node is a leaf
            if not (root.left or root.right):
                root = None
            # the node is not a leaf and has a right child
            elif root.right: 
                root.val = successor(root)
                root.right = self.deleteNode(root.right, root.val)
            # the node is not a leaf, has no right child, and has a left child    
            else:
                root.val = predecessor(root)
                root.left = self.deleteNode(root.left, root.val)
                        
        return root
```