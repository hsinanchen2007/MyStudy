迭代遍历全部路径，对每一个结点都以其为终点向前搜寻符合条件的路径段
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import Counter
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root: return 0
        res = 0
        count = 0
        if root.left: count += 1
        if root.right: count += 1
        node_deque = [[root, count, root.val], ]
        if root.val == sum: res += 1
        while node_deque:
            if node_deque[-1][1] == 0:
                for n, c, v in node_deque[::-1]:
                    if c == 0: node_deque.pop()
                    else: break
            else:
                n, c, v = node_deque[-1]
                c_next = 0
                if c == 2: n_next = n.left
                if c == 1: 
                    if not n.right: n_next = n.left
                    else: n_next = n.right
                node_deque[-1][1] -= 1
                if n_next.left: c_next += 1
                if n_next.right: c_next += 1
                v_n = [x[2] for x in node_deque]
                v_n_c = Counter(v_n)
                res += v_n_c[n_next.val + v - sum]
                #if n_next.val + v - sum in v_n: res += 1
                if n_next.val + v == sum: res += 1
                node_deque.append([n_next, c_next, n_next.val + v])
        return res
```
