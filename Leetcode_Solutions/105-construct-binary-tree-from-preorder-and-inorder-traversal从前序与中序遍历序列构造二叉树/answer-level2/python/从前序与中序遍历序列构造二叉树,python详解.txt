### 解题思路
1、前序遍历：根>左>右，中序遍历:左>根>右
2、递归的基础操作：前序遍历得到根节点，**中序遍历通过根节点找到左节点与右节点**
3、递归的返回条件：当preorder和inorder为空时，返回

```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

首先根据 preorder 找到根节点是 3
然后根据根节点将 inorder 和 preorder分成左子树和右子树

左子树
preorder[9] 
inorder [9]

右子树
preorder[20,15,7] 
inorder [15,20,7]

对右子树preorder[20,15,7]，找到根节点 20
继续划分：

左子树
preorder[15] 
inorder [15]

右子树
preorder[7] 
inorder [7]

重复操作....

直到所有 preorder 和 inorder 都为空，返回 null 即可
```

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0:
            return None
        
        root = TreeNode(preorder[0])
        mid_index = inorder.index(preorder[0])
        # 构建左子树
        root.left = buildTree(preorder[1:mid_index+1], inorder[:mid_index])
        # 构建右子树
        root.right = buildTree(preorder[mid_index+1:], inorder[mid_index+1:])
        
        return root

```