### 解题思路
二叉树的中序遍历是升序的，那么把中序遍历的左中右顺序改为右中左，则这样的遍历是降序的。
把二叉树的所有结点看作一个降序序列，降序遍历每个数，每次都把上一个数累加到下一个数中即可。
递归可以轻松完成上述操作。

### 代码

```java
class Solution {
    private int add;
    public TreeNode convertBST(TreeNode root) {
        if(root == null)    return null;
        root.right = convertBST(root.right);
        root.val += add;
        add = root.val;
        root.left = convertBST(root.left);
        return root;
    }
}
```