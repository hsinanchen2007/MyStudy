### 解题思路
留下了太菜的泪水:只有参考题解中大佬的代码思维来理解。
1、叶子节点是指左右子节点都为None的情况，
2、当root节点的左右子节点都为None,返回1，说明当前节点就是叶子节点，或者此时叶子节点和根节点重合，也就是[1]的情况，整个二叉树就只有一个根节点/叶子节点
3、当root节点的左右子树**有一个不为空**，就应该递归去找另一个不为空的子节点的深度，此时就是：递归函数(不为空的节点)+1；加1是因为此时的深度有一个了啊，就是这个不为空的子节点
4、当root节点的左右子树**都不为空**，应该返回左右子节点中最小的那个，加1是因为有当前这个root节点的高度就是1啊
5、有错误的地方，还请大佬能为我指出来。感激不尽！

### 代码

```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root==None:
            return 0
        if root.left==0 and root.right==0:
            return 1
        if root.left==None and root.right!=None:
            return self.minDepth(root.right)+1
        if root.right==None and root.left!=None:
            return self.minDepth(root.left)+1

        return min(self.minDepth(root.left),self.minDepth(root.right))+1
      
```