```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def height(root:TreeNode):
            if root==None:
                return -1
            max_height=0
            list1=[]
            now_node=root
            now_step=0
            list1.append((now_node,now_step))
            while list1:
                now_node,now_step=list1.pop(0)
                if now_step>max_height:
                    max_height=now_step
                if now_node.left:
                    list1.append((now_node.left,now_step+1))
                if now_node.right:
                    list1.append((now_node.right,now_step+1))
            return max_height
        
        def bfs(root:TreeNode):
            list1=[]
            now_node=root
            now_step=0
            list1.append((now_node,now_step))
            while list1:
                now_node,now_step=list1.pop(0)
                if abs(height(now_node.left)-height(now_node.right))>1:
                    return False

                if now_node.left:
                    list1.append((now_node.left,now_step+1))
                if now_node.right:
                    list1.append((now_node.right,now_step+1))
            return True
        if root==None:
            return True
        
        return bfs(root)
```