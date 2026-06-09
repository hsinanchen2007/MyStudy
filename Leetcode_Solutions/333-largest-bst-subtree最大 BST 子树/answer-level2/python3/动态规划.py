### 解题思路
二叉树的动态规划
参考打家劫舍3[valleft,numleft,booleft,maxval1,minval1]
每个节点存储【该节点的value，以这个节点为根节点的树的节点数，是否是BTS树，以这个节点为根节点的树中最大值，以这个节点为根节点的树中最小值】

判断：1、左节点<根节点 2、右节点>根节点 3、左右子树都是BT树 4、左子树中最大值<根节点 5、右子树中最小值>根节点

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        if not root:
            return 0
        res=[]
        def helper(root):
            if not root:
                return [-1,0,True,-1,10000]
            if not root.left and not root.right:
                res.append(1)
                return [root.val,1,True,root.val,root.val]
            [valleft,numleft,booleft,maxval1,minval1]=helper(root.left)
            # print([valleft,numleft,booleft,maxval1,minval1])
            [valright,numright,booright,maxval2,minval2]=helper(root.right)  
            # print([valright,numright,booright,maxval2,minval2])
            if (valleft==-1 or root.val>valleft) and (valright==-1 or root.val<valright) \
and booleft and booright and (valright==-1 or minval2>root.val) \
and (valleft==-1 or maxval1<root.val) :
                res.append(1+numleft+numright)
                maxvalue=max(root.val,maxval1,maxval2)
                minvalue=min(root.val,minval1,minval2)
                return [root.val,1+numleft+numright,True,maxvalue,minvalue]
            else:
                return [root.val,0,False,-1,10000]
        helper(root)
        return max(res)
```