递归实现DPS。
大致思路是：如果n任意一节点的左子树或右子树不为BST那么以这个节点为根的子树也不为BST，而如果第一个条件成立，还需要判断是否左子树的最大值小于当前节点值，以及右子树最小值是否小于当前节点的值。如果两个条件均成立，则在返回值中标记以该节点为根的子树是BST，同时返回子树中节点的个数以及最大值和最小值，用于递归上一层的条件判断。
```
class Solution:
    def __init__(self):
        self.Max=0
    def largestBSTSubtree(self, root: TreeNode) -> int:
        def BSTtest(node):
            if node is None:
                return [True,0,None,None]
            else:
                res_left=BSTtest(node.left)
                res_right=BSTtest(node.right)
                if res_left[0] and res_right[0]:
                    leftIsBST,rightIsBST=True,True
                    if node.left is not None:
                        if res_left[3]>=node.val:
                            leftIsBST=False
                    if node.right is not None:
                        if res_right[2]<=node.val:
                            rightIsBST=False
                    if leftIsBST and rightIsBST:
                        self.Max=max(res_left[1]+res_right[1]+1,self.Max)
                        min_inSub=node.val if res_left[2] is None else res_left[2]
                        max_inSub=node.val if res_right[3] is None else res_right[3]
                        return [True,res_left[1]+res_right[1]+1,min_inSub,max_inSub]
                    else:
                        return [False,0,None,None]
                else:
                    return [False,0,None,None]
        BSTtest(root)
        return self.Max
```
