### 解题思路
1.自底向顶
对二叉树做先序遍历，自底向顶依次计算每一点的最大高度（前提是这一点为根节点的子树平衡），如果在回溯过程中，发现某一子树不平衡，直接提前返回-1
时间复杂度:最差情况下，需要递归遍历树的所有节点O(N)
空间复杂度：最差情况下（树退化为链表时），系统递归需要使用O(N)的栈空间。
2.从顶至底(会有大量重复运算)
先构造一个函数获取当前节点最大深度，对每一点进行判断时，先计算左右子树高度差是否小于2，再去判断左右子树是否平衡，当三者都成立时，以当前探索节点为根节点的子树平衡。
O(N^2):isBalanced(root) 遍历树所有节点占用O(N)；遍历每个节点时需要判断这个节点的左右子树是否平衡，以及子树高度差是否小于2，这个时间复杂度为O(N)
最差情况下（树退化为链表时），系统递归需要使用O(N)的栈空间。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
#自底向顶
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def recur(root):
            if not root: return 0
            left = recur(root.left)
            if left == -1: return -1
            right = recur(root.right)
            if right == -1: return -1
            return max(left, right) + 1 if abs(left - right) < 2 else -1

        return recur(root) != -1
#从顶至底
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True
        return abs(self.depth(root.left) - self.depth(root.right)) <= 1 and \
            self.isBalanced(root.left) and self.isBalanced(root.right)

    def depth(self, root):
        if not root: return 0
        return max(self.depth(root.left), self.depth(root.right)) + 1

