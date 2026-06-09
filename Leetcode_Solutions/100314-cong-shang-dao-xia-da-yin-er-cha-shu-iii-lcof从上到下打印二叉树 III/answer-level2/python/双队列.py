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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:return []
        ans = []
        Qp = [root]
        Qn = []
        while Qp or Qn:
            anstmp = []
            while Qp:
                tmp = Qp.pop()
                anstmp.append(tmp.val)
                if tmp.left:Qn.append(tmp.left)
                if tmp.right:Qn.append(tmp.right)
            if anstmp:ans.append(list(anstmp))
            anstmp = []
            while Qn:
                tmp = Qn.pop()
                anstmp.append(tmp.val)
                if tmp.right:Qp.append(tmp.right)
                if tmp.left:Qp.append(tmp.left)
            if anstmp:ans.append(list(anstmp))
        return ans
            




```