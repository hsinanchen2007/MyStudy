- max :   统计每个最大的个数。
- 每个节点统计规则：
1. 不同于之前数据，重新开辟新的统计
2. 相同之前数据，情况1:查找左右路径，比较是否最长
3. 相同之前数据，情况2:找出左右最长的路径，返回长度给上一级节点用  


class Solution(object):
    def __init__(self):
        self.max = 0
        
    def helper(self,root,preVal):
        if root is None:
            return 0
        if root.val == preVal:
            l = self.helper(root.left,root.val)
            r = self.helper(root.right,root.val)
            if l + r > self.max:
                self.max = l + r
            return max(l,r) + 1
        else:
            self.helper(root,root.val)
            return 0
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        else:
            self.helper(root,root.val)
            return self.max