### 解题思路
此处撰写解题思路

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
        self.result = []
        self.record_path = []

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.storage(root, sum)
        return self.result

    def storage(self, root: TreeNode, sum: int):
        if not root:
            return 
        self.record_path.append(root.val)
        sum -= root.val
        self.storage(root.left, sum)
        self.storage(root.right, sum)
        if not root.left and not root.right and sum == 0:
            self.result.append(self.record_path.copy())
        self.record_path.pop()
        

```