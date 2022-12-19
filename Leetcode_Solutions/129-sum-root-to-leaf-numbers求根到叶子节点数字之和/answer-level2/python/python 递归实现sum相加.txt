### 解题思路
每次递归，传入node节点和上次递归的node的值作为father
这样每次递归的时候，当前的father是上个递归节点的father*10再加当前node的值
递归结束的标志是传入的node无left和right节点，这时就将当前节点的father(一条链路的总和)和全局变量sum相加


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    sum = 0
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.get_node_values(root, 0)
        return self.sum


    def get_node_values(self, node, father):
        if node is None:
            return
        else:
            father = father*10+node.val
            if node.left is None and node.right is None:
                self.sum = self.sum + father
                return
            self.get_node_values(node.left, father)
            self.get_node_values(node.right, father)
```