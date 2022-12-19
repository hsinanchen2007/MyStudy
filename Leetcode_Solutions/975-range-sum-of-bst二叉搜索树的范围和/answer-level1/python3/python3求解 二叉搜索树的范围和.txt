### 解题思路
1. 根节点表示的输入时树的层序遍历，由于是二叉搜索树，故先用递归的中序遍历转化为有序数组
2. 对数组中指定范围的数字进行相加求和，返回该和即为所求
3. 该方法比较好想到，但是时空复杂度并不是最优
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:

        res = []
        def inOrder(root):
            if not root:return None

            inOrder(root.left)
            res.append(root.val)
            inOrder(root.right)

            return res

        res = inOrder(root)
        index_L = res.index(L)
        index_R = res.index(R)
        sum = 0

        for i in range(index_L,index_R+1):
            sum += res[i]

        return sum
```