由题意知，此题考查根据有序数组建立最小二叉树，很容易想到使用递归方法。
代码如下：
```python
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def build_tree(lst, left, right):
            if left == right:
                return None
            else:
                mid = (left + right) // 2
                node = TreeNode(lst[mid])
                node.left = build_tree(lst, left, mid)
                node.right = build_tree(lst, mid + 1, right)
                return node
        return build_tree(nums, 0, len(nums))
```