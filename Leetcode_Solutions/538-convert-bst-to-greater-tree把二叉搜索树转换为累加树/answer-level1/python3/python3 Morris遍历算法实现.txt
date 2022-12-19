### 解题思路
与官方题解3类似。添加getpre(node)辅助函数用于获取node节点的前驱节点，即node节点的右子树中的最小值对应的节点。

时间复杂度：O(n)
空间复杂度：O(1)
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
        value=0
        cur=root
        while cur:
            if cur.right:
                pre=self.getpre(cur)
                if pre.left==cur:
                    cur.val+=value
                    value=cur.val
                    pre.left=None
                    cur=cur.left
                else:
                    pre.left=cur
                    cur=cur.right
            else:
                cur.val+=value
                value=cur.val
                cur=cur.left
        return root
            
    def getpre(self,node):
        pre=node.right
        while pre.left and pre.left!=node:
            pre=pre.left
        return pre
```