### 解题思路
1. BFS，通过两个列表记录当前层数的值，和下一层的node从而遍历出每一层的值
2. 递归去遍历每一层的值，同时判断若存在下一层的值就去遍历

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
        # ans = list()
        # if not root:
        #     return ans
        # current_node = [root]
        # while current_node:
        #     current_ans = []
        #     next_level = []
        #     for i in current_node:
        #         current_ans.append(i.val)
        #         if i.left:
        #             next_level.append(i.left)
        #         if i.right:
        #             next_level.append(i.right)
        #     ans.append(current_ans)
        #     current_node = next_level
        # return ans

        ans = []
        if not root:
            return ans
        
        def helper(node, level):
            if len(ans) == level:
                ans.append([])

            ans[level].append(node.val)
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)

        helper(root, 0)
        return ans       
```