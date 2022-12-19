```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # 首先计算边界，root为空则返回深度0
        if not root:
            return 0
        # 先将最小深度定义为无穷大，便于第一次更新
        self.min_depth = float('inf')
        
        # 定义一个函数，参数为目前遍历到的节点与这个节点的深度
        def helper(node,level):
            # 首先判断该节点是否已经超过了目前找到的最小深度，若超过可以直接返回，没有遍历其子节点的必要
            if level >= self.min_depth:
                return
            # 此时该节点深度足够小
            # 接着判断该节点是否叶节点，即左右子节点皆为空，若是，则更新最小深度后返回
            if not node.left and not node.right:
                self.min_depth = level
                return
            # 此时该节点非叶节点
            # 那么继续遍历其存在的左右子节点
            if node.left:
                helper(node.left, level+1)
            if node.right:
                helper(node.right, level+1)
            return
        # 初始化更新过程，root的深度设为1
        helper(root, 1)
        return self.min_depth
```
