### 解题思路
我的思路：中序遍历+列表遍历,这题和【570】不是类似吗= =
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)

### 代码

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        cha_min = float('inf')
        lists = []
        def inOrder(root):
            if not root:
                return None
            inOrder(root.left)
            lists.append(root.val)
            inOrder(root.right)
        inOrder(root)
        for i in range(len(lists)-1):
            cur = lists[i+1] -lists[i]
            cha_min = min(cha_min,cur)
        return cha_min
```