### 解题思路
树递归得好好锤炼一下，自己写这个又慢又容易出错。

想不清楚每个节点怎么处理的。

最好还是在 root 节点就判断是否有左右节点比较好。
不要不管 root.left root.right 为 None 仍然要判断。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        # 后续遍历
        def sum_node(root, val):  #在 root 节点就判断是否有左右节点比较好
#            if root==None:
#                return 0
            if root.right:
                right_val = sum_node(root.right, val)
                root.val += right_val
            else:
                root.val += val

            if root.left:
                left_val = sum_node(root.left, root.val)
                return left_val
            else:
                return root.val

        if root == None:
            return 
        sum_node(root, 0)
        
        return root
```

``` python3 刚开始写，各种 bug 代码

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        # 后续遍历
        def sum_node(root, val):
            if root==None:
                return val  # 这里不是 return 0
            val = sum_node(root.right, val)
            root.val += val
            sum_node(root.left, root.val)
            return root.val

        if root == None:
            return 
        sum_node(root, 0)
        
        return root

```