前半部分先BFS逐层找到我们要的比较起点，之后再去递归比较，要注意递归为子集的多个判定条件
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not B:
            return False
        target_val = B.val
        target = A if A.val == target_val else None

        nodes = [A]
        next_layer = []
        while nodes:
            for node in nodes:
                if node.left:
                    if node.left.val == target_val:
                        target = node.left
                        nodes = None
                        break
                    next_layer.append(node.left)
                
                if node.right:
                    if node.right.val == target_val:
                        target = node.right
                        nodes = None
                        break
                    next_layer.append(node.right)
            nodes = next_layer
            next_layer = []
        
        if not target:
            return False 
        return self.compare(target, B)

    def compare(self, A, B):
        if not A and B:
            return False
        elif not B:
            return True
        elif not B.left and not B.right and B.val == A.val:
            return True
        elif B.val != A.val:
            return False
        else:
            return self.compare(A.left, B.left) and self.compare(A.right, B.right) 
        
```
