### 解题思路
1.DFS（循环）：依次去探索可能的节点，判断是否需要更新，时间复杂度O(H)，H为树的高度，N个节点，一般情况下H为logN，最坏情况为N，空间复杂度O(H)
2.中序遍历：
时间复杂度：O(N)，对每个元素都要去探索
空间复杂度：O(N)，使用了一个数组存储中序序列。（另外还要加上递归栈深度O(H)但加上之后还是O(N)）
3.二分查找，和第一种方法思路很像，依次去探索可能的节点，判断是否需要更新最小值
时间复杂度：O(H)
空间复杂度：O(1)
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
#DFS
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        if not root:
            return
        minval, r = float('inf'), None
        stack = [(root, abs(root.val - target))]
        while stack:
            node, v = stack.pop(0)
            if v < minval:
                minval = v
                r = node.val
            if target < node.val and node.left:
                stack.append((node.left, abs(node.left.val - target)))
            if target > node.val and node.right:
                stack.append((node.right, abs(node.right.val - target)))
        return r
#中序遍历得到二叉搜索树每个节点的元素值从小到大排列的一个数组，然后在找到zuixaoz
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        
        return min(inorder(root), key = lambda x: abs(target - x))
#二分查找
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        closest = root.val
        while root:
            closest = min(root.val, closest, key = lambda x: abs(target - x))
            root = root.left if target < root.val else root.right
        return closest
```