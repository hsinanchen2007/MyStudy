
![二叉树深度.png](https://pic.leetcode-cn.com/2575c6b97cef5e3ad0d2b06fbf1ac71d8266791120a4a0413d7d57f797398c86-%E4%BA%8C%E5%8F%89%E6%A0%91%E6%B7%B1%E5%BA%A6.png)



获取到左子树和右子树的深度，大的+1 就是该树的深度

```java []
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = maxDepth(root.left);
        int right = maxDepth(root.right);

        return left > right ? left + 1 : right + 1;
    }
}
```
