### 解题思路
此题和[Diameter of binary tree]解题思路类似
**算法关键**：
- 定义一个递归函数 `sum_all(node)`， 来计算 以x节点为根的子树上 所有节点之和。再递归调用x节点的左儿子`node.left`和右儿子`node.right`，得到L和R。则以x节点为根的子树节点之和为 `L+R+node.val`.
- 定义一个全局变量`self.res`来计算每个节点的坡度



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
        self.res=0
        def sum_all(node):
            if not node: return 0
            L=sum_all(node.left)
            R=sum_all(node.right)
            self.res+=abs(L-R)
            return L+R+node.val
        sum_all(root)
        return self.res

```