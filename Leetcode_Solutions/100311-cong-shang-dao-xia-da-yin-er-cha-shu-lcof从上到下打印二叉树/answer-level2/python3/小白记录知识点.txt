### 解题思路
此处撰写解题思路
collections.deque()生成一个双向队列，可以从左侧出，右侧进，左侧进等操作。
利用广度优先策略，从上到下每一行进行遍历。
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        ans = []
        queue = collections.deque()
        queue.append(root)
        while queue:
            x1 = queue.popleft()   
            ans.append(x1.val)
            if x1.left:
                queue.append(x1.left)
            if x1.right:
                queue.append(x1.right)

        return ans
    #    def dfs(node,ans):
    #        if node
```