```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        # (X, Y) => (X - 1, Y - 1)
        #        => (X + 1, Y - 1)
        # from top to bottom
        # if position is same: smaller value first
        # root => (0, 0)

        # 3 => (0, 0)
        # 9 => (-1, -1)
        # 20 => (1, -1)
        # 15 => (0, -2)
        # 7 => (2, -2)

        # traverse : O(N)
        # sorted : O(NlogN)
        # sapce: O(N)

        left, right = float('inf'), float('-inf')
        dic = collections.defaultdict(list)
        def traverse(node, x, y):
            nonlocal left, right
            if node == None: return
            left = min(left, x)
            right = max(x, right)
            dic[x].append((y, node.val))
            traverse(node.left, x - 1, y - 1)
            traverse(node.right, x + 1, y - 1)
        # corner case
        if root == None: return []
        traverse(root, 0, 0)
        res = []
        for i in range(left, right + 1):
            res.append([item[1] for item in sorted(dic[i], key = lambda x: (-x[0], x[1]))])
        return res

            

```