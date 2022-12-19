### 解题思路
二叉搜索树，左子树部分均比根节点小，右子树部分均比根节点大，所以，从整个树的根节点开始找，当第一次找到某个节点，该节点的值小于给定节点的较大值，大于给定节点的较小值，则该节点即为返回值。
1、首先比较给定的两个节点，找到较大值和较小值
2、从整棵树的根节点开始，当根节点不为空时
3、如果根节点的值大于较大值，则取根节点的左孩子作为新的根节点
4、如果根节点的值小于较小值，则取根节点的右孩子作为新的根节点
5、当找到某个节点处于中间值，则返回
6、当未找到中间值，此时根节点为空，说明不存在这样的根节点，返回None


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val > q.val:
            maxNode=p
            minNode=q
        else:
            maxNode=q
            minNode=p
        while root:
            if root.val>maxNode.val:
                root=root.left
            elif root.val<minNode.val:
                root=root.right
            else:
                return root
        return None


```