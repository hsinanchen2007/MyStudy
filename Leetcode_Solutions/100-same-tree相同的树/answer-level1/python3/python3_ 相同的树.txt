```python
# 递归方法
def isSameTree(p: TreeNode, q: TreeNode) -> bool:
    # 如果存在为空节点情况下, 则直接优先判断.
    if not p or not q:
        return p == q
    # 判断值是否相等, 并且递归判断左节点, 右节点是否相等
    return p.val == q.val and isSameTree(p.left, q.left) and isSameTree(p.right, q.right)

from collections import deque
def isSameTree1(p: TreeNode, q: TreeNode) -> bool:
    # 判断两个节点是否相等
    def help(p, q):
        if not p or not q: return p == q
        return p.val == q.val
    # 使用双端队列, 存储元祖
    deq = deque([(p, q)])
    while deq:
        # 每个同级的节点进行判断
        p, q = deq.popleft()
        if not help(p, q): return False
        # 将相同的节点放入队列中, 循环判断
        if p:
            deq.append([p.left, q.left])
            deq.append([p.right, q.right])
    return True
```