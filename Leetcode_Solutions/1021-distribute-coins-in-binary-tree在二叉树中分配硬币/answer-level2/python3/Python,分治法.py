### 解题思路
1.分治法
2.将左右子树的硬币都放置到顶端节点，保证左右子树每个顶点的硬币都为1，顶点数为负就是差多少硬币，为正就是多余的硬币
3.累计每个子树移动硬币所需要的步数
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        def check_tree(root):#空节点那么，就返回，视为已经有1个硬币，不需要移动的节点
            if not root:
                return 1, 0
            lcoins, lsteps = check_tree(root.left)#获取左子树顶点硬币数量与左子树移动的步数
            rcoins, rsteps = check_tree(root.right)#获取右子树顶点硬币数量与右子树移动的步数
            return root.val + lcoins + rcoins - 2, lsteps + rsteps + abs(lcoins - 1) + abs (rcoins - 1)
            #返回顶点硬币数量则为，顶点本身数量加上左右硬币数量扣除左右顶点自身所需要的硬币
            #步数则为左右子树步数之和，加上把左右子树顶点硬币移动至顶点的步数
        coins, steps = check_tree(root)
        return steps
```