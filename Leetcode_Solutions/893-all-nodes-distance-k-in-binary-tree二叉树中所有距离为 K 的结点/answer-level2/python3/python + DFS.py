```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:	
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) ->  List[int]:
        # K <= 1000
        # node.val <= 500
        res = []
        def getChild(node, K, layer):
            if node == None: return False
            if K == layer: 
                res.append(node.val)
                return
            getChild(node.left, K, layer + 1)
            getChild(node.right, K, layer + 1)

        def getParent(node, target):
            if node is None: return (False, 1)
            if node is target: return (True, 1)
            leftFlag, leftLayer = getParent(node.left, target)
            rightFlag, rightLayer = getParent(node.right, target)
            if leftFlag:
                if leftLayer == K: res.append(node.val) # special case
                getChild(node.right, K - leftLayer, 1)
                return (True, leftLayer + 1)
            if rightFlag:
                if rightLayer == K: res.append(node.val) # special case
                getChild(node.left, K - rightLayer, 1)
                return (True, rightLayer + 1)
            return (False, 1)
                
        getChild(target, K, 0)
        getParent(root, target)
        return res
```