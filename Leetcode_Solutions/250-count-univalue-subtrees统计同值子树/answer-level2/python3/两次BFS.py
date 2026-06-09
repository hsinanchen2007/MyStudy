```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        if root==None:
            return 0
        
        def sametree(root:TreeNode):
            list1=[]
            list1.append(root)
            val=root.val
            while list1:
                now_node=list1.pop(0)
                if now_node.val!=val:
                    return False
                if now_node.left:
                    list1.append(now_node.left)
                if now_node.right:
                    list1.append(now_node.right)
            return True
        
        rs=0
        list2=[]
        list2.append(root)
        while list2:
            now_node=list2.pop(0)
            if sametree(now_node):
                rs+=1
            if now_node.left:
                list2.append(now_node.left)
            if now_node.right:
                list2.append(now_node.right)
        return rs
```
