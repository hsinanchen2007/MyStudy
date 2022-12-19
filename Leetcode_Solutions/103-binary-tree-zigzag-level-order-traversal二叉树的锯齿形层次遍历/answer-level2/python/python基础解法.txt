### 解题思路
和102的思路一样，可以通过递归和dfs分别实现，就是多加个条件，depth % 2 ==0来判断是否翻转

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        # ans = list()
        # if not root:
        #     return ans
        # depth = 0
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
        #     if depth % 2 == 1:
        #         current_ans = current_ans[::-1]
        #     depth += 1
        #     ans.append(current_ans)
        #     current_node = next_level
        # return ans

        ans = []

        def dfs(root, level):
            if not root:
                return []
            if len(ans) == level:
                ans.append([])
            if level % 2 == 0:
                ans[level].append(root.val)
            else:
                ans[level].insert(0, root.val)
            dfs(root.left, level+1)
            dfs(root.right, level+1)
        dfs(root, 0) 
        return ans   
        
```