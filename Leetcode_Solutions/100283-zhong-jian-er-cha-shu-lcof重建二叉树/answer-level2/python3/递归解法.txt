### 解题思路

思路一样，只是在递归的时候传递的是子数组，同样的解法Python要比Java省很多代码（不需要定义额外的函数）。

### 代码

```python3 []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.helper(preorder, inorder)

    def helper(self, pre: List[int], inorder: List[int]) -> TreeNode:
        if len(pre) == 0:
            return None
        root = TreeNode(pre[0])
        index = inorder.index(pre[0])
        root.left = self.helper(pre[1:index + 1], inorder[0:index])
        root.right = self.helper(pre[index + 1:], inorder[index + 1:])
        return root

```
```java []
class Solution {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0) {
            return null;
        }
        return recursiveBuild(preorder, inorder);
    }

    public TreeNode recursiveBuild(int[] pre, int[] inorder) {

        TreeNode root = new TreeNode(pre[0]);
        int index = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == pre[0])
                index = i;
        }

        if (index < 1) {
            root.left = null;
        } else {
            root.left = recursiveBuild(Arrays.copyOfRange(pre, 1, index + 1), Arrays.copyOfRange(inorder, 0, index));
        }

        if (pre.length <= index + 1) {
            root.right = null;
        } else {
            root.right = recursiveBuild(Arrays.copyOfRange(pre, index + 1, pre.length),
                    Arrays.copyOfRange(inorder, index + 1, inorder.length));
        }

        return root;
    }
}
```

