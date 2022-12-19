### 解题思路
如果中序遍历能够获得升序序列的话，那么也很容易想到对称中序遍历（右根左遍历）能够获得降序序列。
注意：题目只需要获得第k大的元素，所以我们并不需要遍历整棵树，当已经获得答案的时候就可以return 了。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        if root is None:
            return None
        res = None
        cnt = 0
        def get_res(root):
            nonlocal res, cnt
            if root is None or cnt == k:
                return 
            get_res(root.right)
            cnt += 1
            if cnt == k:
                res = root.val
                return 
            get_res(root.left)
        get_res(root)
        return res
```