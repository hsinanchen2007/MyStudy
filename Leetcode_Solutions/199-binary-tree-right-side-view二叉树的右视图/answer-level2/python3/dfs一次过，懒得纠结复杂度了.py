### 解题思路
![image.png](https://pic.leetcode-cn.com/56b0eb3de5254c7045567290dbadec19ea8e6a0095ca13848c8c865691c80432-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        # dfs
        if not root:
            return []
        res = []
        stack = [root]
        

        def dfs(root, depth=0):
            if not root:
                return
            if depth == len(res):
                res.append([root.val])
            else:
                res[depth].append(root.val)
            dfs(root.left, depth+1)
            dfs(root.right, depth+1)
        dfs(root)
        return [x[-1] for x in res]
        
        
            

        


```