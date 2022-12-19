### 解题思路
思路：先序遍历,主要是判断条件 当左右子树没有则直接保存到res数组

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root:
            return []
        res=[]
        def helper(root,temp):
            if not root:
                return
            if root.right==root.left==None:
                # 这一步很重要判断左右子树是否为空 空则直接断链
                res.append(temp+[str(root.val)])
                temp=[]
            helper(root.left,temp+[str(root.val)])
            helper(root.right,temp+[str(root.val)])
        helper(root,[])
      
        return ['->'.join(nums) for nums in res]
```