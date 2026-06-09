bi话少说，直接上代码（简单易懂），-----这是某大神的思路，借鉴借鉴
方法一：
（中序）层次遍历
    
    class Solution:
        def recoverTree(self, root: TreeNode) -> None:
            """
            Do not return anything, modify root in-place instead.
            """
            
            stack= []
            one = two = None
            temp = TreeNode(float("-inf"))
            while root or stack:
                while root:
                    stack.append(root)
                    root = root.left
                root = stack.pop()
            
                if temp.val!=None and temp.val>root.val:
                    if one == None:
                        one = temp
                    two = root
                    '''     注释掉的这一部分也是可以运行的，为了简洁而已
                if not one and temp.val>root.val:
                    one = temp
                if one and temp.val>root.val:
                    two = root
                    '''         
                temp = root
                root = root.right
            

方法二：
递归

    class Solution:
        def recoverTree(self, root: TreeNode) -> None:
            """
            Do not return anything, modify root in-place instead.
            """
            self.one = self.two = None
            self.temp = TreeNode(float("-inf"))
        
            self.inorder(root)
        
            self.one.val,self.two.val = self.two.val,self.one.val

        def inorder(self,root):
            if not root:return None
            self.inorder(root.left)
            if self.temp.val!=None and self.temp.val>root.val:
                    if self.one == None:
                        self.one = self.temp
                    self.two = root 
            self.temp = root
            self.inorder(root.right)

        #one.val,two.val = two.val,one.val