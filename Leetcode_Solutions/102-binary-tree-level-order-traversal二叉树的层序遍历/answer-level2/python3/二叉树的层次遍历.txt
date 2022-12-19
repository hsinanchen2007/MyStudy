### 解题思路
层次遍历是广度优先遍历算法，依次遍历每一层数据，同一层的左右孩子结点的数据存放在同一个列表里，所有层的列表的列表，是最终结果。

#### 原作者：LeetCode

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = [] # 用于存储每一层的节点值
        if not root:
            return levels
        
        def helper(node, level): 
            if len(levels) == level:  
                # 当前的level值是用于确定是哪一层，同一层的值要存到同一个
                levels.append([]) # 在列表中新增一个列表元素，存放当前层的结点
            levels[level].append(node.val)  # append the current node value
            if node.left: # 递归处理左孩子，左孩子的孩子存到下一层
                helper(node.left, level + 1)
            if node.right:  # 递归处理右孩子，右孩子的孩子存到下一层
                helper(node.right, level + 1)
        helper(root, 0)  # 从0层开始，即根结点开始
        return levels


                

```