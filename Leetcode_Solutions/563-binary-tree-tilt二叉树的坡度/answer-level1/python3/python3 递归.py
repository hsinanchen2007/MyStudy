### 解题思路
与一般的递归不同的是，我们在每个节点需要做两个事情：
1、计算本节点的梯度
2、计算本子树的和，返回给父亲，便于父亲计算它的梯度

而且，在None节点和叶子节点，我们也需要做不同的事情：
1、None节点，我们返回0，表明本子树的和为0
2、叶子节点，返回节点值



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        tilt_list=[]
        def search_every_node(root):
            if not root:
                return 0
            if not root.left and not root.right:
                return root.val
            left=search_every_node(root.left)
            right=search_every_node(root.right)
            tilt_list.append(abs(left-right))
            return left+right+root.val
        search_every_node(root)
        return sum(tilt_list)


```