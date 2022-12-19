```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Codec:
    #层次遍历的变种
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:return []
        stack = deque([root])
        res = []
        cur_level = 1
        next_level = 0

        while cur_level>0: #stack or cur_level>0
            cur = stack.popleft()

            if cur:
                cur_level -= 1
                res.append(cur.val)
                stack.append(cur.left)
                stack.append(cur.right)
                    
                if cur.left:
                    next_level+=1
                if cur.right:
                    next_level+=1
            else:
                res.append('null')

            
            if cur_level==0:
                cur_level=next_level
                next_level = 0

        return res

    #根据二叉树的性质，编号i（i>=1）的节点，左节点为2*i,右节点为2*i+1
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        self.length = len(data)
        if self.length < 1:return None
        
        def buildTree(num):
            new_node = TreeNode(data[num-1])
            if 2*num <= self.length:
                new_node.left = buildTree(2*num)
            if 2*num+1 <= self.length:
                new_node.right = buildTree(2*num+1)
            
            return new_node
        
        return buildTree(1)
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
