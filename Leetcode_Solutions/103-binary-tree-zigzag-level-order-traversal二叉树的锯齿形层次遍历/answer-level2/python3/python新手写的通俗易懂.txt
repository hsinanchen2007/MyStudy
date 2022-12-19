首先算出树的深度，递归依次计算单双层树的内容，填充进去。
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        n = 0
        out = []
        def maxDepth(root):
            if root==None:
                return 0
            else:
                return 1+max(maxDepth(root.left),maxDepth(root.right))
        length = maxDepth(root)
        [out.append([]) for _ in range(length)]
        def dns(root:TreeNode, n:int, out):
            if n%2 == 0:
                out[n].append(root.val)
            else:
                out[n].insert(0,root.val)
            if not (root.right or root.left):
                return out
            if root.right is None:
                return dns(root.left, n+1 , out)
            if root.left is None:
                return dns(root.right, n+1, out)
            else:
                return dns(root.left, n+1, out) and dns(root.right, n+1, out)
        return dns(root,n,out)