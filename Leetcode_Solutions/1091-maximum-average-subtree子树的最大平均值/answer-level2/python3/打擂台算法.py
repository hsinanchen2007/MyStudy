```
class Solution:
    res_max_sum = 0
    res_size = 0
    res_node = None
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        self.helper(root)
        return self.res_max_sum / self.res_size
    
    def helper(self, node):
        # 递归的出口
        if not node:
            # 返回空node的sum和size
            return 0, 0
        
        # 无脑递归左右子树
        left_sum, left_size = self.helper(node.left)
        right_sum, right_size = self.helper(node.right)
        
        # 计算当前节点的sum和size
        node_sum = left_sum + right_sum + node.val
        node_size = left_size + right_size + 1
        
        # 打擂台，找最大平均值
        if self.res_max_sum == 0 or self.res_max_sum * node_size < node_sum * self.res_size:
            self.res_max_sum = node_sum
            self.res_size = node_size
            self.res_node = node
        
        # 返回当前节点的sum和size
        return node_sum, node_size
```
