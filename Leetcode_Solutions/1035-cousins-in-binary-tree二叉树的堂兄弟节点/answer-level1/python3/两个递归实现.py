class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        
        def myfun(root,target,depth):
            if root==None:
                return 0
            if target==root.val:
                return depth
            depth += 1
            return max(myfun(root.left,target,depth),myfun(root.right,target,depth))

        depth=0
        xd=myfun(root, x, depth)
        depth = 0
        yd = myfun(root, y, depth)
        if xd!=yd: 
            return False
        
        def myfun2(root,target):
            if root==None:
                return -1
            if root.left==None and root.right==None:
                return -1
            if root.left!=None and target==root.left.val:
                return root.val
            if root.right!=None and target==root.right.val:
                return root.val
            return max(myfun2(root.left,target),myfun2(root.right,target))

        px=myfun2(root,x)
        py=myfun2(root,y)
        #print(px,py)
        if px==py:
            return False
        else:
            return True