后序遍历两次
第一次放摄像头
第二次数摄像头
别问为什么不边放边数，懒得改了-.-

第一遍：
返回0表示是空节点（自身是None）
返回1表示是叶节点/自己不用放摄像头要爸爸节点管的（左右是0或3）
返回2表示是摄像头节点，同时val置为1（左右有1）
返回3表示是不用管的节点，儿子是摄像头或者没有儿子（左右是0或2）

第二遍数val

注意根节点如果是上述的情况1，是没有爸爸要的，再加一个1即可
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorder(self,root):
        if root==None:
            return 0#空
        lval=self.postorder(root.left)
        rval=self.postorder(root.right)
        if (lval==0 or lval==3) and (rval==0 or rval==3):
            return 1#叶子/自己不是，但是要管
        elif lval==1 or rval==1:
            root.val=1
            return 2#摄像头
        elif lval==2 or rval==2:
            return 3#不用管
    def postordercount(self,root):
        if root==None:
            return 0
        lval=self.postordercount(root.left)
        rval=self.postordercount(root.right)
        return lval+rval+root.val
    def minCameraCover(self, root: TreeNode) -> int:
        if root==None:
            return 0
        self.postorder(root)
        if (root.left==None or root.left.val==0) and (root.right==None or root.right.val==0) and root.val==0:
            return self.postordercount(root)+1#根是要被管的时候，没有父节点了，只能自己为摄像头
        return self.postordercount(root)
        
```
