### 解题思路
通过mirrors算法得到中序遍历列表，然后判断是否严格递增
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import operator
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        res = self.mirrors(root)
        if all([res[i] < res[i+1] for i in range(len(res)-1)]):
            return True
        return False
    
    def mirrors(self, root:TreeNode) -> List[int]:
        ans = []
        while root:
            if not root.left:
                ans.append(root.val)
                root = root.right
            else:
                pre = self.get_pre(root)
                if not pre.right:
                    pre.right = root
                    root = root.left
                elif pre.right == root:
                    pre.right = None
                    ans.append(root.val)
                    root = root.right
        return ans

    def get_pre(self, root:TreeNode)-> TreeNode:
        p = root.left
        if not p.right:
            return p
        while p.right and p.right!=root:
            p = p.right
        return p
```