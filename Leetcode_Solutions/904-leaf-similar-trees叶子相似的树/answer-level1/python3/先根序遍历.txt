一 算法思路
首先，定义一个求叶值序列的函数。考虑到叶子的值按从左到右的顺序排列，可以使用树的任意一种深度优先遍历方法（本题解使用先根序遍历），如果遍历的节点为叶子节点，则将其添加到结果中。
然后，对于两颗树分别调用求叶值序列的函数，若果所得叶值序列相同，则为叶子相似的树，反之，不是。
二 算法实现
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def get_leaves(node):
            res = []
            st = []
            p = node
            while p is not None or st:
                while p is not None:
                    st.append(p.right)
                    if p.left is None and p.right is None:
                        res.append(p.val)
                    p = p.left
                p = st.pop()            
            return res
        
        res1 = get_leaves(root1)
        res2 = get_leaves(root2)
        if res1 == res2:
            return True
        else:
            return False
```
三 复杂度分析
1 时间复杂度
O(max(N1, N2))，其中N1为root1中节点数，N2为root2中节点树。
2 空间复杂度
O(max(H1, H2))，其中H1为root1的高度，H2为root2的高度。