```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ans = []
        def findfather(ans,root,p,q):
            if root == None: return False
            if root != p and root != q: # 本身不是节点
                left = findfather(ans,root.left,p,q)
                right = findfather(ans,root.right,p,q)
                if left and right: # 如果左右各找到了，则该节点是LCA
                    ans.append(root)
                    return True
                elif left or right: # 如果只有一个找到了，那么返回True给上层
                    return True
                else:
                    return False
            else: # 本身是其中一个节点
                left = findfather(ans,root.left,p,q)
                right = findfather(ans,root.right,p,q)
                if left or right:
                    ans.append(root)
                return True
        
        findfather(ans,root,p,q)
        return ans[0]

```
