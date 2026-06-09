```python
from typing import List, Optional

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder or not postorder: return
        root = TreeNode(postorder[-1])
        mid = inorder.index(root.val)
        root.left = self.buildTree(inorder[:mid], postorder[:mid])
        root.right = self.buildTree(inorder[mid + 1:], postorder[mid:-1])
        return root

#参考：https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-
#            traversal/discuss/221681/Don't-use-top-voted-Python-solution-for-interview-here-is-why.

    def buildTree1(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        map_inorder = {val: i for i, val in enumerate(inorder)}

        def recur(low: int, high: int) -> Optional[TreeNode]:
            if low >= high: return
            root = TreeNode(postorder.pop())
            mid = map_inorder[root.val]
            root.right = recur(mid + 1, high)
            root.left = recur(low, mid)
            return root

        return recur(0, len(inorder))
```