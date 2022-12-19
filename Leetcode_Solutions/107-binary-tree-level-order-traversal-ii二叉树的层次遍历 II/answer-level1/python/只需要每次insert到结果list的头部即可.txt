### 解题思路
真的太骗人了，还以为要从底部开始遍历，想想也不可能啊，肯定是从root往下遍历的；

原来考察的是list.insert每次可以往开头放置元素啊

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


import collections
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        result = []
        queue = collections.deque([root])
        while queue:
            num = len(queue)
            curr_data = []
            for _ in range(num):
                curr_node = queue.popleft()
                curr_data.append(curr_node.val)
                if curr_node.left:
                    queue.append(curr_node.left)
                if curr_node.right:
                    queue.append(curr_node.right)

            result.insert(0, curr_data)
        return result

```