### 解题思路
从根节点开始遍历右节点，再遍历左节点，并得出当前节点值及其排位，递归直到排位为k为止。

### 代码

```python3
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        return self.kLargest(root, k)[-1]

    def kLargest(self, root: TreeNode, k: int) -> (int, int):
        if root.left is None and root.right is None:
            return 1, root.val
        else:
            n = 0
            if root.right is not None:
                n, v = self.kLargest(root.right, k)
                if n == k:
                    return n, v
            n = n + 1
            v = root.val

            if root.left is not None and n < k:
                nr, v = self.kLargest(root.left, k - n)
                return n + nr, v

            return n, v
```