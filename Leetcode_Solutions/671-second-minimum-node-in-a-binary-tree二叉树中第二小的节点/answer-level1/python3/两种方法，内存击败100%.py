### 解题思路
分析
* 根为最小的值
* 若root != left != right
    * return min(left, right)
* 若root == left ( or root == right )
    * 返回secondMinimum(left)(若有)
    * 否则return right
* 若root == left == right
    * 返回min(secondMinimum(left), secondMinimum(right))

### 代码

```python[]()
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        def v1(root):
            if root.left is None:
                return -1
            if root.val != root.left.val and root.val != root.right.val:
                return min(root.left.val, root.right.val)
            if root.val == root.left.val == root.right.val:
                minLeft = self.findSecondMinimumValue(root.left)
                minRight = self.findSecondMinimumValue(root.right)
                return min(minLeft, minRight) if minLeft != -1 and minRight != -1 else max(minLeft, minRight)
            if root.val == root.right.val:
                root.right, root.left = root.left, root.right
            # root.left.val == root.val
            minLeft = self.findSecondMinimumValue(root.left)
            return min(minLeft, root.right.val) if minLeft != -1 else root.right.val
        def v2(root):
            if root.left is None: return -1

            left, right = root.left.val, root.right.val

            if root.val != left and root.val != right: return min(left, right)

            if root.val == right: right = self.findSecondMinimumValue(root.right)
            if root.val == left: left = self.findSecondMinimumValue(root.left)
            if left == right == -1: return -1
            if right == -1: return left
            if left == -1: return right
            return min(left, right)
        return v2(root)
```