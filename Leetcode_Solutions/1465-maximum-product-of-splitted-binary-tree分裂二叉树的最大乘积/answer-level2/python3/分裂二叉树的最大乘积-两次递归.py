* step1: 递归求总节点数`val_sum`。
    * 递归公式：`当前节点数=左子树节点数+1+右子树节点数`  
    * 基线条件：当前节点为空，返回0
* step2: 递归求最大乘积`res`。
    * 设以该节点为根节点的子树为`tree1`，原二叉树与`tree1`的差集为`tree2`
    * 用step1中递归的思想求出`tree1节点数=左子树节点数+1+右子树节点数`，令`temp=tree1节点数*tree2节点数`，如果大于`res`，则更新`res`。

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        
        def valSum(root):
            if root is None:
                return 0
            return valSum(root.left) + root.val + valSum(root.right)
        
        val_sum = valSum(root)
        
        self.res = 0
        
        def getRes(root):
            if root is None:
                return 0
            curr = getRes(root.left) + root.val + getRes(root.right)
            temp = curr * (val_sum - curr)
            if temp > self.res:
                self.res = temp
            return curr
        
        getRes(root)
        
        return int(self.res%(1e9+7))
```