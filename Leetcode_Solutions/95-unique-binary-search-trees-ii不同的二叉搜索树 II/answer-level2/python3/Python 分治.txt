
1. 分治，对于第k个数，把问题分解为求解小于k的左子树集合和大于k的右子树集合，两个集合的循环组合即为第k个数作为根节点的解。
2. 采用递归实现，边界条件为子树有0个或1个元素
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        Listn = [i for i in range(1, n+1)]
        def gt(List):
            res = []
            if not List:
                return [None]
            if len(List) == 1:
                return [TreeNode(List[0])]
            for k in range(len(List)):
                for left in gt(List[:k]):
                    for right in gt(List[k+1:]):
                        node = TreeNode(List[k])
                        node.left  = left
                        node.right = right
                        res.append(node)
            return res
        if n==0:
            return []
        return gt(Listn)
```
