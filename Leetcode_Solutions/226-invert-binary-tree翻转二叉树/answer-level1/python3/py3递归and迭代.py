#递归
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        
        
        root.left,root.right = self.invertTree(root.right),self.invertTree(root.left)

        return root

#迭代

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        
        stack = [root]
        while len(stack) > 0:
            temp = stack.pop()
            temp.left,temp.right = temp.right,temp.left
            if temp.right is not None:
                stack.append(temp.right)
            if temp.left is not None:
                stack.append(temp.left)
        return root