### 解题思路
利用二叉搜索树的性质，中序遍历得到一个单调递减的数组（注意此处顺序应该是右子节点-根节点-左子节点）；并使用pre存储上一节点的值，初始化为0，随着遍历不断更新，实现原地修改各节点的值。

时间和空间复杂度主要体现在树的遍历中，遍历过程中本代码使用的是迭代法，而非递归。
时间复杂度：O(n)
空间复杂度：O(n)
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
        node=root
        stack=[]
        pre=0
        while node or stack:
            if node:
                stack.append(node)
                node=node.right
            else:
                node=stack.pop()
                node.val+=pre
                pre=node.val
                node=node.left
        return root
```