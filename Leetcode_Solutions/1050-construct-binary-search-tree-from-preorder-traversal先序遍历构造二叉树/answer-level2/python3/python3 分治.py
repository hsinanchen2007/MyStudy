### 解题思路
preorder的第一个元素作为root.val
将比其小的元素存放在leftList里
比其大的元素存放在rightList里
递归调用，分别建好左子树和右子树
返回root
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        leftList = []
        rightList = []
        root = TreeNode(preorder[0])
        for num in preorder[1:]:
            if num < preorder[0]:
                leftList.append(num)
            elif num > preorder[0]:
                rightList.append(num)
        root.left = self.bstFromPreorder(leftList)
        root.right = self.bstFromPreorder(rightList)
        return root
```