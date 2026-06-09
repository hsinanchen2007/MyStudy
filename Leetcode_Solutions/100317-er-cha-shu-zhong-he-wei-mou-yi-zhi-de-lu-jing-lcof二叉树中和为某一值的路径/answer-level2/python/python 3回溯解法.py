事实上随便写写我也不知道为什么能击败 92%和 100%
### 解题思路
回溯，如果当前是叶子节点且和相等就添加路径并返回
若不是叶子节点，就向左右孩子深入

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res=[]
        def traceback(node,trace,sum):
            if not node:
                return 
            if node.val==sum and (not node.left) and (not node.right):
                res.append(trace+[node.val])
                return
            if node.left:
                traceback(node.left,trace+[node.val],sum-node.val)
            if node.right:
                traceback(node.right,trace+[node.val],sum-node.val)
        traceback(root,[],sum)
        return res
                
            
```