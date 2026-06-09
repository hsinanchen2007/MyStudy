
![image.png](https://pic.leetcode-cn.com/76ea720b6c6ce772f3823f615f968423054132b63176bed30620ed56cba3799c-image.png)

```
class Solution {
    public int maxDepth(TreeNode root) {
        return deeper(root);
    }
    
    private int deeper(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        return Math.max(deeper(root.left), deeper(root.right)) + 1;
    }
}
```
