### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        def searchBST(root, val):
            # 如果是叶子结点 返回这个节点
            if not root.left and not root.right: 
                return root
            # val小于root.val时
            # 如果root还有左节点则向左所搜
            # 如果root没有左节点了则把当前val插入作为其左节点
            if val < root.val:
                if root.left:
                    return searchBST(root.left, val)
                else:
                    return root
            # val大于root.val同理
            else:
                if root.right:
                    return searchBST(root.right, val)
                else:
                    return root

        # 找到合适的插入位置
        node = searchBST(root, val)
        # 判断插入到左侧还是右侧
        if val < node.val:
            node.left = TreeNode(val)
        else:
            node.right = TreeNode(val)
        
        return root
```