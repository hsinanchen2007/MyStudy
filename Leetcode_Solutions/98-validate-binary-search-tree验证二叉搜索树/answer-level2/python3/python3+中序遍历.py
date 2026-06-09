### 解题思路
中序遍历，比较排序后的数组和原数组是否一样，以及有没有相同的元素

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        def helper(root,ans):
            if not root:
                return
            helper(root.left,ans)
            ans.append(root.val)
            helper(root.right,ans)
            return ans
        ans = helper(root,[])
        # print(ans)
        return sorted(ans) == ans and len(set(ans)) == len(ans)
            
            
```