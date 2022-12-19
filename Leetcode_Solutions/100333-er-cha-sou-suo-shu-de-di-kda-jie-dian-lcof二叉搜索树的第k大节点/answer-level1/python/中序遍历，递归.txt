### 解题思路
此处撰写解题思路
递归停止条件：当输入节点为None时停止，return。
利用ans记录当前的数值。
中序遍历，左根右。
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        ans=[]
        def dfs(node):
            if node == None:
                return
            dfs(node.left)
            ans.append(node.val)
            dfs(node.right)
        dfs(root)
        return ans[-k]
```