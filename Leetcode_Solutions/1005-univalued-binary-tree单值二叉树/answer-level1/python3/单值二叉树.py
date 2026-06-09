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

# 思路：获取第一个节点的值，后面的跟这个值对比，一旦出现不一致，则直接退出，这样比较节省时间
#       也可以先获取每一个节点的值，存到列表里，然后len(set(values))，如果等于1，那么就是单值，否则非单值。第二种方法需要完整遍历，消耗时间更长，存储空间也会更多
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        values = []

        def dfs(node):
            if node:
                values.append(node.val)
                if len(set(values)) > 1:
                    return False
                else:
                    dfs(node.left)
                    dfs(node.right)
            return len(set(values)) == 1

        return dfs(root)
        # return len(set(values)) == 1

        # 
        # if root is None:
        #     return False
        # else:
        #     value = root.val
        # nodeList = []
        # while root.left is not None or nodeList:
        #     nodeList.append(root.right)
        #     while root.left is not None:
        #         if root.left.val != value:
        #             return False
        #     root = nodeList.pop()
        # return True

        # LeetCode官方解法：
        # left_correct = (not root.left or root.val == root.left.val and self.isUnivalTree(root.left))
        # # 左孩子为空，或者根节点的值和左孩子的值相同，并且左孩子作为根节点的那棵子树是单值
        # right_correct = (not root.right or root.val == root.right.val and self.isUnivalTree(root.right))
        # # 右孩子为空，或者根节点的值和右孩子的值相同，并且右孩子作为根节点的那棵子树是单值
        # return left_correct and right_correct   # 左子树和右子树都是单值
   
```