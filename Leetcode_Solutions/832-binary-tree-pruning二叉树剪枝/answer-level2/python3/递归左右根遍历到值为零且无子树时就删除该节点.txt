![image.png](https://pic.leetcode-cn.com/24e68d02bfbd3401b3c9840a17d371cb031ed3185d70f9ee915f8e6c2eaa6a8b-image.png)


左右根遍历，保证了在删空了子树时，如果根结点也是0，那就能继续删掉根结点。

```
class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if root:
            root.left=self.pruneTree(root.left)
            root.right=self.pruneTree(root.right)
            if root.val==0 and not root.left and not root.right:
                return
            return root
```
