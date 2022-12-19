```python
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left, self.right = None, None
        
def generateTrees(n):
    """
        1. dp问题: dp[i] = dp[i - 1]为左子树 * dp[i+1]为右子树
    """
    d = {}
    if not n:
        return []
    def help(i, j):
        if (i, j) in d:
            return d[(i, j)]
        ans = []
        for v in range(i, j + 1):
            # 递归找到所有的左子树
            for left in help(i, v - 1):
                # 递归找到所有的右子树
                for right in help(v + 1, j):
                    root = TreeNode(v)
                    root.left, root.right = left, right
                    ans += [root]
        # 将i,j对应的结果存储起来
        d[(i, j)] = ans or [None]
        return d[(i, j)]
    return help(1, n)

print(generateTrees(8))
```