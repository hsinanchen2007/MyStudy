**一 二叉搜索树的检索**
（一）算法思路
根据二叉搜索树的性质：
如果val小于当前结点的值，转向其左子树继续搜索；如果val大于当前结点的值，转向其右子树继续搜索；如果已找到，则返回当前结点。
如果搜索到最后仍未找到结点，则返回None。
（二）算法实现
```
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        p = root
        while p:
            if val < p.val:
                p = p.left
            elif val > p.val:
                p = p.right
            else:
                return p
        return None
```
（三）复杂度分析
时间复杂度：O(log(N)),N为树中节点数。特殊情况树畸形时，时间复杂度为O(N)。
空间复杂度：O(1)。
**二 二叉搜索树的插入**
（一）算法思想
1如果二叉搜索树为空树，用val构造二叉树节点作为根节点并返回。
2否则，搜索新结点的插入位置，沿子结点关系向下：
遇到应该走向左子树而左子树为空，或者应该走向右子树而右子树为空时，就是找到了新字典项的插入位置，构造新结点并完成实际插入。
之后，返回根节点。
（二）算法实现
```
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None:
            root = TreeNode(val)
            return root
        p = root
        while True:
            if val < p.val:
                if p.left is None:
                    p.left = TreeNode(val)
                    return root
                p = p.left
            else:
                if p.right is None:
                    p.right = TreeNode(val)
                    return root
                p = p.right
        
#         if root is None:
#             root = TreeNode(val)
#             return root
#         par = None
#         p = root
#         while p is not None:
#             if val < p.val:
#                 par = p
#                 p = p.left
#             else:
#                 par = p
#                 p = p.right
        
#         p = TreeNode(val)
#         if val < par.val:
#             par.left = p
#         else:
#             par.right = p
#         return root
```
（三）复杂度分析
时间复杂度：树的高度，即O(logN)，N为书中节点数。当树畸形时，可能为O(N)。
空间复杂度：O(1)。
**三 二叉搜索树的删除**
（一）算法思想
1 检索要删除的节点p，并在检索的过程中记录其父结点par。
2 删除节点
假设已经确定应该删除节点p,它是其父节点par的左子节点。（为右子节点的情况类似）
（1）如果p为叶子节点，直接删除。即令par的左子节点为空。
（2）如果p.left为空树，这事只需把p的右子树改为其父结点par的左子树。
（3）p有左子树，这时先找到p的左子树的最右节点，设为r,显然它没有右子树。用p的左子节点代替par的左子节点，并将p的右子树作为r的右子树。
（二）算法实现
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        par = None
        p = root
        while p:
            if key < p.val:
                par = p
                p = p.left
            elif key > p.val:
                par = p
                p = p.right
            else:
                if p.left is None and p.right is None:
                    if par is None:
                        root = None
                    else:
                        if key < par.val:
                            par.left = None
                        else:
                            par.right = None
                elif p.left is None:
                    if par is None:
                        root = p.right
                    else:
                        if key < par.val:
                            par.left = p.right
                        else:
                            par.right = p.right
                else:
                    r = p.left
                    while r.right is not None:
                        r = r.right
                    if par is None:
                        root = p.left
                        r.right = p.right
                    else:
                        if key < par.val:
                            par.left = p.left
                            r.right = p.right
                        else:
                            par.right = p.left
                            r.right = p.right
                return root
                                                    
        return root
```
（三）复杂度分析
时间复杂度：O(log(N)),N为树中节点个数。二叉搜索树退化时，时间复杂度变为线性。
空间复杂度：O(1)。
