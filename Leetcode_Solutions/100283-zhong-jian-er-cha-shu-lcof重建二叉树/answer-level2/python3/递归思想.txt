### 解题思路
暴力解法，给左右子树分别再开两个数组存前序和中序遍历用以递归，数组长度为一时递归结束。
非常暴力还费内存，欢迎大家一起优化

### 代码

```python3
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) != len(inorder) or preorder == [] or inorder == []:
            return None

        # 提取根节点
        root = TreeNode(preorder[0])
        root_index = inorder.index(root.val)
        if len(preorder) == 1:
            return root
        # 递归遍历左子树
        left_in = inorder[:root_index]
        left_pre = preorder[1:1+len(left_in)]
        root.left = self.buildTree(left_pre,left_in)
        # 右子树
        right_in = inorder[root_index+1:]
        right_pre = preorder[1+len(left_in):]
        root.right = self.buildTree(right_pre,right_in)
        
        return root
```