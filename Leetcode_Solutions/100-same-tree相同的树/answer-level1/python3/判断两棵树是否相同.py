### 解题思路
递归大法好

对比两棵树的节点指针p和q：
1、两棵树不同有两种情况：
   1) 两棵树的结构不同，即结点的位置不同
   2) 两棵树的数值不同，即结点的数值不同
2、两棵树相同只有一种情况：结点位置相同并且结点的值相同

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:  # 递归终止条件：两个需要对比的结点都为空，即已经到树的末梢了
            return True

        if p is None or q is None:  # 两棵树不同的情况1：两棵树中只有一棵树有左孩子结点或者只有一棵树有右孩子结点
            return False
        
        if p.val != q.val:   # 两棵树不同的情况2：对比的两个结点的值不同
            return False
        else:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)   # 递归处理


```