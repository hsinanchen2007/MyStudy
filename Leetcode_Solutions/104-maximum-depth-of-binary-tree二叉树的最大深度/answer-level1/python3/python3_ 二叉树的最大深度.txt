```python
def maxDepth(root: TreeNode) -> int:
    maxLevel = 0
    def help(n, r=0):
        nonlocal maxLevel
        # 到达叶子节点时候, 判断深度
        if not n:
            maxLevel = max(maxLevel, r)
            return
        # 递归判断
        help(n.left, r + 1)
        help(n.right, r + 1)
    
    help(root)
    return maxLevel

# 简化的递归
def maxDepth1(root: TreeNode) -> int:
    if not root: return 0
    left, right = maxDepth1(root.left), maxDepth1(root.right)
    # 通过max, 会自动过滤掉深度较小的
    return max(left, right) + 1
```