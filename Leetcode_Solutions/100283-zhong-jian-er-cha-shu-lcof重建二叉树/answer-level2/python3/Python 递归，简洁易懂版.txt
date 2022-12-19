### 解题思路
前序遍历的第一个值为根节点，则根据此根节点在中序遍历中的位置可分成左子树和右子树，进而又可根据左子树和右子树的长度实现对前序遍历的划分，形成递归求解。
由于涉及中序遍历中查找根节点索引的问题（在列表中查找索引时间复杂度是O(n)），利用一个字典存储值和索引的关系，加速查询过程O(1)。

### 执行结果
![image.png](https://pic.leetcode-cn.com/d2bd71181e0c1f25ea6a2b72042d7e92cd1c81ba61010ed9b4ab8d553c851f9c-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        maps = {num:index for index, num in enumerate(inorder)}
        def helper(l1, r1, l2, r2):
            #l1、r1分别为当前处理preorder的左右边界，l2、r2分别为当前处理inorder的左右边界
            if l1>r1:
                return None
            root = TreeNode(preorder[l1])
            pivot = maps[preorder[l1]]
            root.left = helper(l1+1, l1+pivot-l2, l2, pivot-1)
            root.right = helper(l1+pivot-l2+1, r1, pivot+1, r2)
            return root
        return helper(0, len(preorder)-1, 0, len(inorder)-1) if preorder else None
```