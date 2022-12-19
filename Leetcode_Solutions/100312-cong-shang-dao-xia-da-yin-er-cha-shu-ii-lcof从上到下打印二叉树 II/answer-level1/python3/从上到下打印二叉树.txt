### 解题思路

参考求二叉树的深度--仍旧是递归

1. list列表添加数据(添加的是root.val)
2. 注意运用level，进行list添加数据(一层一层地添加数据--广度优先遍历)
3. 原始定义的返回list为[]，利用list[level].append()会超出list定义范围

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
        if not root: return []
        level_list = []
        def list_levelOrder(node, level):
            if not node:return level
            if len(level_list) == level:
                # print(len(level_list), level)
                # list为[]，利用list[level].append()会超出list定义范围
                level_list.append([])
            level_list[level].append(node.val)
            left = list_levelOrder(node.left, level + 1)
            right = list_levelOrder(node.right, level + 1)
            return max(left, right)
        list_levelOrder(root, 0)
        return level_list
```