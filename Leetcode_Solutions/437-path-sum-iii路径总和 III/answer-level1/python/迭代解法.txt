遍历到某个节点时，能找到之前所有可能的连续路径和即可。
空间换时间的思路下，用栈和用队列感觉上没啥区别。
```
from typing import List, Dict, Tuple, Deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    # def pathSum(self, root: TreeNode, target: int) -> int:
    #     def helper(node: TreeNode, temp: int):
    #         if node is None:
    #             return 0
    #         rem = temp - node.val
    #         res = 1 if rem == 0 else 0
    #         return res + helper(node.left, rem) + helper(node.right, rem)
    #
    #     if root is None:
    #         return 0
    #     return helper(root, target) + self.pathSum(root.left, target) + self.pathSum(root.right, target)

    # def pathSum(self, root: TreeNode, target: int) -> int:
    #     def helper(node: TreeNode, prev: int, hmap: Dict[int, int]) -> int:
    #         if node is None:
    #             return 0
    #         prev += node.val
    #         res = hmap.get(prev - target, 0)
    #         hmap[prev] = hmap.get(prev, 0) + 1
    #         res += helper(node.left, prev, hmap) + helper(node.right, prev, hmap)
    #         hmap[prev] = hmap.get(prev) - 1
    #         return res
    #
    #     hmap: Dict[int, int] = {0: 1}
    #     return helper(root, 0, hmap)

    # def pathSum(self, root: TreeNode, target: int) -> int:
    #     if root is None:
    #         return 0
    #     ans = 0
    #     stack: List[Tuple[TreeNode, List[int]]] = [(root, [root.val])]
    #     while stack:
    #         node, sums = stack.pop()
    #         ans += sums.count(target)
    #         sums.append(0)
    #         if node.left:
    #             stack.append((node.left, [_sum + node.left.val for _sum in sums]))
    #         if node.right:
    #             stack.append((node.right, [_sum + node.right.val for _sum in sums]))
    #     return ans

    # def pathSum(self, root: TreeNode, target: int) -> int:
    #     from collections import deque
    #     if root is None:
    #         return 0
    #     ans = 0
    #     queue: Deque[Tuple[TreeNode, List[int]]] = deque([(root, [root.val])])
    #     while queue:
    #         size = len(queue)
    #         for _ in range(size):
    #             node, sums = queue.popleft()
    #             ans += sums.count(target)
    #             sums.append(0)
    #             if node.left:
    #                 queue.append((node.left, [_sum + node.left.val for _sum in sums]))
    #             if node.right:
    #                 queue.append((node.right, [_sum + node.right.val for _sum in sums]))
    #     return ans

    # 丧心病狂版本
    def pathSum(self, root: TreeNode, target: int) -> int:
        if root is None:
            return 0
        ans = 0
        stack: List[Tuple[TreeNode, List[int]]] = [(root, [root.val])]
        while stack:
            node, sums = stack.pop()
            ltmp, rtmp = [], []
            for i, _sum in enumerate(sums):
                if _sum == target:
                    ans += 1
                if node.left:
                    ltmp.append(_sum + node.left.val)
                if node.right:
                    rtmp.append(_sum + node.right.val)
            if node.left:
                ltmp.append(node.left.val)
                stack.append((node.left, ltmp))
            if node.right:
                rtmp.append(node.right.val)
                stack.append((node.right, rtmp))
        return ans
```
