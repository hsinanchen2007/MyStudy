### 解题思路
假设根节点的order向左向右“分裂”，第一次分裂的权值为1，则左子树的order-1，右子树的order+1；
接下来继续分裂，下一步分裂则左右权值都变为上次的一半即1/2，则继续左子树-权值，右子树+权值。
如此递归，并记录权值及对应的节点值形成字典，该权值必不重复，且与元素大小直接对应，排序后取序号k-1的字典值便为所求。

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
        if not root:
            return
        ord_dict = {}
        ord_list = []
        def dfs(root, order=0, split=1):
            if not root:
                return
            ord_dict[order] = root.val
            ord_list.append(order)
            dfs(root.left, order-split, split/2)
            dfs(root.right, order+split, split/2)
        dfs(root)
        ord_list.sort()
        return ord_dict[ord_list[k-1]]


            

```