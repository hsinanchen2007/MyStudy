```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # 后序 递归算法
        # res=[]
        # def Traversal1(root):
        #     if root!=None:
        #         Traversal1(root.left)
        #         Traversal1(root.right)
        #         res.append(root.val)
        # Traversal1(root)
        # return res
        
        # 后序 迭代算法
        res=[]
        stack=[]
        
        while root!=None or len(stack)!=0:
            if root!=None:
                # 入栈
                stack.append(root)
                # 继续迭代左节点
                root=root.left
            else:
                # 先出栈
                p=stack.pop()
                # 迭代右节点
                root=p.right
                
                # 右节点为空 访问该节点
                if p.right==None:
                    res.append(p.val)
                # 右节点不为空 继续迭代
                else:
                    # 将当前节点的右节点置为None 再将其放回stack
                    p.right=None
                    stack.append(p)

        return res
        
```
