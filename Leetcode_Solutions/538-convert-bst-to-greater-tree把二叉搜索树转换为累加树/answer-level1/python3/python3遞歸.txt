### 解题思路
此处撰写解题思路
       """
        模拟一个三层的树，可以看出来就是右->中->左来遍历整个树，每次经过一个节点时，就需要将
        该节点的值累加给下一个遍历的节点，所以用一个变量来记录整个需要累加的值，遇到一个变量，
        先增加该值，再将这个值加上自身，作为下一个节点累加的数值
        """
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
 
        if root == None:
            return None
        self.sum = 0


        def dfs(root):
            if root == None:
                return
            dfs(root.right)
            self.sum += root.val
            root.val = self.sum
            dfs(root.left)
            return root
        return dfs(root)





```