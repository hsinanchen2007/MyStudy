```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        res = -float('inf')  
        stack = [root]
        visited = []
        while stack:
            r = stack.pop()
            visited.append(r)
            if r.left:
                stack.append(r.left)
            if r.right:
                stack.append(r.right)
                
        # 后序遍历
        # r的子节点的值已经被更新成，从r往下的最大路径和
        for r in visited[::-1]:
            # 计算通过r的最大路径和
            ret = r.val
            if r.left and r.left.val > 0:
                ret += r.left.val
            if r.right and r.right.val > 0:
                ret += r.right.val
            res = max(res, ret)
            
            # 更新r.val为从r往下的最大路径和
            ret = r.val
            if r.left:
                ret = max(ret, r.left.val + r.val)
            if r.right:
                ret = max(ret, r.right.val + r.val)
            r.val = ret
             
        return res
```
![TIM截图20190921180226.png](https://pic.leetcode-cn.com/8ab7f7b441ba01f46b3373e3b6c1070ff15d5c7277e5f6df91e68674c051c415-TIM%E6%88%AA%E5%9B%BE20190921180226.png)
