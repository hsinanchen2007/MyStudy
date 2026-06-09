### 解题思路
DFS比BFS速度差不多，个中原因想不懂

### 代码

![image.png](https://pic.leetcode-cn.com/278e505352f52fd552602f024a4148359980135a536160aabfbef12796433ad2-image.png)

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        # 1.层次遍历（BFS？）
        count = 0
        queue = [root]
        cur = root
        while queue != []:
            node = queue.pop(0) # 用列表实现队列的先进先出

            for son in [node.left, node.right]:
                if son:
                    queue.append(son)

            if node.val % 2 == 0:
                for son in [node.left, node.right]:
                    if son != None:
                        for grandson in [son.left, son.right]:
                            if grandson != None:
                                count += grandson.val
        return count

![image.png](https://pic.leetcode-cn.com/29c3c2489329c4a78149a6557deb05256b266ecd3a2ac06e6106599041062a1a-image.png)

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    count = 0
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        # 2.DFS(暴力搜索，计算冗余大)        
        def dfs(root):
            if root:
                for son in [root.left, root.right]:
                    if son:
                        dfs(son)
                if root.val % 2 == 0:
                    for son in [root.left, root.right]:
                        if son:
                            for grandson in [son.left, son.right]:
                                if grandson:
                                    self.count += grandson.val
        dfs(root)
        return self.count


        
                                
                        


        


```