```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        # 不用队列 我真是把自己秀得呱呱叫叫，广度搜索
        if not root: return []
        
        ans, level = [], 0
        dpq = []
        dpq.append(root)
        while dpq:
            qs = len(dpq)  
            ans.append([])
            for i in range(qs):
                node = dpq.pop()
                ans[level].append(node.val)
                if node.left:
                    dpq.insert(0,node.left)
                if node.right:
                    dpq.insert(0,node.right)
            if level % 2 != 0:
                ans[level] = ans[level][::-1]
            level += 1           
        return ans

```
