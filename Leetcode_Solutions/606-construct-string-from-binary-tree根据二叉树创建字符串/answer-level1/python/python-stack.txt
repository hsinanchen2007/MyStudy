```
class Solution(object):
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t:
            return ''
        stack = [(t, 0)]
        res = ''
        while stack:
            node, h = stack.pop()
            if h > 0:
                res += '('
            res += str(node.val) if node else ')'
            if not node:
                continue
            if node.left or node.right:
                # 根据题意，表示left为null的情况
                if node.right:
                    stack.append((node.right, h+1))
                stack.append((node.left, h+1))
            elif node.left is None and node.right is None:
                # 遍历到叶节点，加上")"
                if stack:
                    # 数量等于 当前节点深 - 栈顶节点深度 + 1
                    n = h - stack[-1][1]+1 
                else:
                    n = h
                for _ in range(n):
                    res += ')'
        return res
```
