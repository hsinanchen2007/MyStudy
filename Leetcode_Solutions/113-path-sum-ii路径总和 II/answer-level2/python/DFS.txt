利用递归做深度搜索。这次的helper函数要增加一个variable temp来记录路径，如果找到了使得总和等于target的leave，则把temp放进结果列表res里：
```
from collections import deque
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        #深度搜索DFS遍历所有路径，保留和为目标值的list
        res = []
        if not root:
            return res
        
        def helper(node, diff, temp):
  
            if diff == 0 and not node.left and not node.right:
                res.append(temp)
            if node.left:
                helper(node.left, diff - node.left.val, temp + [node.left.val])
            if node.right:
                helper(node.right, diff - node.right.val, temp + [node.right.val])
        
        helper(root, sum - root.val, [root.val,])
        return res
            
        
```
