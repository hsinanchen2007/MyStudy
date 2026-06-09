### 解题思路
此处撰写解题思路
1. 构造一个中序遍历函数：使用递归方法；
2. 利用二叉搜索树的特性，中序遍历的函数结果是一个从小到大的有序结果；
3. 再取第k小的元素即可；
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def help(root,res):
            if root == None:
                return res
            help(root.left, res)
            res.append(root.val)
            help(root.right, res)
        res = []
        help(root, res)
        # print(res)
        return res[k-1]
```