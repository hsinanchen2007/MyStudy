### 解题思路
深度遍历思想进行回溯，遇到叶节点保存到列表
输出列表

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = []
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        #recurse
        def recurse(node,s):
            if node: 
                s= s +'->'+str(node.val)
                recurse(node.left,s)
                recurse(node.right,s)
                if not node.left and not node.right:
                    self.ans.append(s[2:])
            return None
        recurse(root,'')
        return self.ans
```