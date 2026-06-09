思路很简单，就是对每个子树都求内部最大路径和到父节点的最大路径，依次递归


class Solution:
    def maxPathSum(self, root: TreeNode) -> int:

        # 对每个子树记录它内部的最大路径和到当前节点的最大路径
        def maxsum(x):
            if not x.left and not x.right:
                return x.val,x.val
            if not x.left:
                sin2,sout2 = maxsum(x.right)
                return max(sin2,sout2+x.val,x.val),max(sout2+x.val,x.val)
            if not x.right:
                sin1,sout1 = maxsum(x.left)
                return max(sin1,sout1+x.val,x.val),max(sout1+x.val,x.val)
            sin1,sout1 = maxsum(x.left)
            sin2,sout2 = maxsum(x.right)
            sout = max(sout1+x.val,sout2+x.val,x.val)
            sin = max(sin1,sin2,sout1+sout2+x.val,x.val,sout)
            return sin,sout
    
        return maxsum(root)[0]
