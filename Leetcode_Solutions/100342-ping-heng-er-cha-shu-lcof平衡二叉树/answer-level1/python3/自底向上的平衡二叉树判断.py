### 解题思路
1. 首先需要理解平衡二叉树,我最开始错误地理解为：
    **所有root到leaf节点的路径**的距离差大于1，则判断不是平衡二叉树。(F)
2. 正确的理解应该为：
    每一个node节点的左右子树的高度差大于1，则判断不是平衡二叉树。(T)

3. 看到由自顶向下的方法，但需要重复遍历节点，即先判断root的左右子树的高度差，再计算root.left的左右子树......

4. 因此可以采用自底向上的方法，每个节点遍历一次，先判断**下层节点的左右子树的高度差**，若不平衡则返回-1，若平衡，则返回**该节点为根节点所表示的树的高度**，递归回到上一层。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:

        def balance(root):
            if root is None:
                return 0
        
            l_height = balance(root.left)
            r_height = balance(root.right)
            # 左右子树是否平衡
            if l_height < 0 or r_height < 0:
                return -1
            # 左右子树的高度差
            if abs(l_height-r_height) <= 1:
                cur_height = max(l_height, r_height) + 1
                return cur_height
            else:
                return -1

        return True if balance(root) >= 0 else False
```