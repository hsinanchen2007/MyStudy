### 解题思路
深度优先遍历，递归时传递层数作为参数，使用map记录每层的最大值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        largest_map = dict()

        def dfs(node, height):
            if not node:
                return

            dfs(node.left, height + 1)
            dfs(node.right, height + 1)

            if largest_map.get(height, None) is None:
                largest_map[height] = node.val
            else:
                largest_map[height] = max(largest_map[height], node.val)

        dfs(root, 0)
        print(largest_map)
        keys_sorted = sorted(largest_map.keys())
        return [largest_map[key] for key in keys_sorted]
```

### 解题思路
使用广度优先搜索进行层次遍历，用一个变量记录每层的最大值

```python3
def largestValues(self, root: TreeNode) -> List[int]:
    """
    多方法解题
    一、 层次遍历   广度优先搜索
    :param root:
    :return:
    """
    from collections import deque
    queue = deque()
    queue.appendleft(root)

    res = []
    while queue:
        n = len(queue)
        max_value = float('-inf')
        for _ in range(n):
            node = queue.pop()

            if node:
                max_value = max(max_value, node.val)
            else:
                return res

            if node.left:
                queue.appendleft(node.left)

            if node.right:
                queue.appendleft(node.right)

        if max_value != float('-inf'):
            res.append(max_value)
    return res
```
