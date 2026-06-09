# 题目要点
叶子节点是指没有子节点的节点。

这一点要尤其注意，题目要求的是从根节点到叶子节点的最小距离。
如果一个根节点只有一棵子树，那么我们需要返回根节点到这棵子树的叶子节点的最小深度。

# 递归（DFS）
递归结束条件：
1. 当根节点的左子树和右子树都为空时，返回1
2. 当根节点的左子树和右子树有一棵为空时，返回非空子树的最小深度
3. 当根节点的左子树和右子树都不为空时，返回左右子树的最小深度

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        left = self.minDepth(root.left)
        right = self.minDepth(root.right)
        
        # 如果左子树为空，返回右子树的最小深度
        if not root.left:
            return right + 1
        
        # 如果右子树为空，返回左子树的最小深度  
        if not root.right:
            return left + 1
        
        return min(left, right) + 1
```

# 迭代（DFS）
每次拿到节点都要先判断一下该节点是否为叶子节点，即，节点是否没有左子节点和右子节点。

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        stack = []
        stack.append((root, 1))
        min_depth = float('inf')
        while stack:
            node, cur_depth = stack.pop()
            children = [node.left, node.right]
            if not any(children):
                min_depth = min(min_depth, cur_depth)
            for child in children:
                if child:
                    stack.append((child, cur_depth+1))
        
        return min_depth
```

# 迭代（BFS）
每次拿到节点都要先判断一下该节点是否为叶子节点，即，节点是否没有左子节点和右子节点。
BFS迭代和DFS迭代的主要差别体现在：BFS是取stack中的第零个元素进行迭代，DFS是取stack中的最后一个元素进行迭代。

```python []
from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        stack = deque([(root, 1)])
        min_depth = float('inf')
        while stack:
            node, cur_depth = stack.popleft()
            children = [node.left, node.right]
            if not any(children):
                min_depth = min(min_depth, cur_depth)
            for child in children:
                if child:
                    stack.append((child, cur_depth+1))
        
        return min_depth
```

# 芝士点
新学习了any()函数的用法：
Return True if any element of the iterable is true. If the iterable is empty, return False.

相当于以下代码效果：
```python []
def any(iterable):
    for element in iterable:
        if element:
            return True
    return False
```

注意，整数0在判断时会被认为是False。


