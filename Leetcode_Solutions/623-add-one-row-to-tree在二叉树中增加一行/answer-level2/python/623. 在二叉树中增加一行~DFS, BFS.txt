### 解题思路
**DFS的思路**
其实就是递归找深度==d-1的节点进行操作
![image.png](https://pic.leetcode-cn.com/0966d6f99fe6209afdb811bdd468d6ba8061f40d5af0226dd6494087f98a7a7d-image.png)

**BFS的思路**
每层元素入队出队，如果层数==d-1,那么对该层的所有出队的元素进行操作

![image.png](https://pic.leetcode-cn.com/84a6e16833d4a2d642cf1fa21c25c913dcee265fe553cb3fb1c892e241327496-image.png)

### 代码（DFS）

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:

        if d == 1: # 当d==1的时候，d-1不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。
            t = TreeNode(v)
            t.left = root
            return t

        def dfs(root, depth, d, val):
            if root is None: # 终止条件
                return 
            if depth == d - 1: # 如果递归的深度等于d-1
                temp_left, temp_right = root.left, root.right # 临时变量
                root.left = TreeNode(val)
                root.right = TreeNode(val)
                root.left.left = temp_left
                root.right.right = temp_right
            else: # 对左右子树递归
                dfs(root.left, depth+1, d, val)
                dfs(root.right, depth+1, d, val)

            return root

        return dfs(root, 1, d, v)


```
### 代码（DFS）

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:

        if d == 1:
            t = TreeNode(v)
            t.left = root
            return t

        depth = 1
        queue = [root] 
        while queue:
            n = len(queue) 
            if depth == d - 1: # 如果层数==d-1
                for _ in range(n): # 对该层的所有元素进行操作
                    node = queue.pop(0)
                    temp_left, temp_right = node.left, node.right
                    node.left, node.right = TreeNode(v), TreeNode(v)
                    node.left.left, node.right.right = temp_left, temp_right
                break
            else:
                for _ in range(n):
                    node = queue.pop(0)

                    if node.left:
                        queue.append(node.left)
                    if node.right:
                        queue.append(node.right)
            depth += 1
        return root


```