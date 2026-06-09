![leetcod_776.png](https://pic.leetcode-cn.com/cdd5b6828408fd6f11ca458a5cf3d91521ca497b76351e2112eaac41fc0df383-leetcod_776.png)

### 解题思路
递归思路化繁为简

递归基，空节点，则返回两个空

递归基，当前节点值恰为要找的值，从此节点劈开，右边子树结点的值都大于目标值 V，剩下的部分结点的值都小于等于给定的目标值 V。

如果当前节点值小于V，对右子树调用此函数，函数返回两颗子树，左子树值小于V，接在当前节点的右子树上，并返回当前节点和之前返回的右子树。

如果当前节点值大于V，对左子树调用此函数，函数返回两颗子树，右子树值大于V，接在当前节点的左子树上，并返回之前返回的左子树和当前节点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def splitBST(self, root: TreeNode, V: int) -> List[TreeNode]:
        if root is None:            #递归基，空
            return None,None
        if root.val == V:           #递归基，恰好分开
            right = root.right
            root.right = None
            return root,right
        if root.val < V:            #当前节点值小于V
            left,right = self.splitBST(root.right,V)
            root.right = left
            return root,right
        if root.val > V:            #当前节点大于V
            left,right = self.splitBST(root.left,V)
            root.left = right
            return left,root
```