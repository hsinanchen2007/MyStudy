### 解题思路
这题其实和101基本没有区别，除了最后反转列表，还有就是insert的时候指定insert(0)也可以实现
1. BFS
2. 递归
具体的可以参考101

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        # ans = []
        # if not root:
        #     return ans
        # current_level = [root]
        # while current_level:
        #     current_ans = []
        #     next_root = []
        #     for i in current_level:
        #         current_ans.append(i.val)
        #         if i.left:
        #             next_root.append(i.left)
        #         if i.right:
        #             next_root.append(i.right)
        #     ans.append(current_ans)
        #     current_level = next_root
        # return ans[::-1]

        ans = []
        if not root:
            return ans
        
        def helper(root, level):
            if len(ans) == level:
                ans.append([])
            ans[level].append(root.val)
            if root.left:
                helper(root.left, level + 1)
            if root.right:
                helper(root.right, level + 1)
        
        helper(root, 0)
        return ans[::-1]
```