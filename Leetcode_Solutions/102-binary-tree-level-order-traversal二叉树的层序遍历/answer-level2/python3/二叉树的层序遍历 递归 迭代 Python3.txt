### 递归解法
执行用时 :40 ms, 在所有 Python3 提交中击败了67.04%的用户
内存消耗 :14.4 MB, 在所有 Python3 提交中击败了5.39%的用户

思路：
其实并不能真正以递归访问数据的顺序（DFS）得到层序遍历的结果（BFS）
但是可以曲线救国，我们在递归函数中加入level参数，将DFS访问到的数据存到BFS相应的层（level）中
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        def dfs(root, level):
            if not root:
                return
            if len(bfs) == level:
                bfs.append([])  # 初始化第level层
            bfs[level].append(root.val)  # 将数据存到第level层
            dfs(root.left, level+1)
            dfs(root.right, level+1)

        bfs = []
        dfs(root, 0)
        return bfs
               
```

### 迭代解法
执行用时 :60 ms, 在所有 Python3 提交中击败了13.49%的用户
内存消耗 :14.1 MB, 在所有 Python3 提交中击败了5.39%的用户

思路：
1. 用队列存每层的节点，每次循环时，当前层节点依次出栈，记录下值，并把自己对应的邻居存入队列中
2. 循环结束时，所有当前层节点出队列，所有下一层节点如队列
3. 两种方法的时间复杂度都是O(N)，空间复杂度O(N)，但是迭代的方法慢很多，个人理解是因为迭代方法比递归方法多了很多入队列出队列的操作。
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res
        
        queue = deque([root, ])
        level = 0
        while queue:
            res.append([])
            for i in range(len(queue)):
                node = queue.popleft()
                res[level].append(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            level += 1
        return res
               
```