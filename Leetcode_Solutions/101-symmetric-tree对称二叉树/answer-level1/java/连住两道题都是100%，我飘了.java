
![镜像树.png](https://pic.leetcode-cn.com/9a1cd31f2225e69ebc49f4d3eaae4c9ac9065516c022a540498dc28044cb5156-%E9%95%9C%E5%83%8F%E6%A0%91.png)


相同树和对称树都是100%，感觉和树相关的，递归着走总没错。

递归条件就是左右子树当前值相同，不同就返回false
相同的前提下满足 左树的左节点等于右树的右节点 且  左树的右节点等于右树的左节点

```java []
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return checkLeftAndRight(root.left, root.right);
    }
    private  boolean checkLeftAndRight(TreeNode left, TreeNode right) {

        if (left == null && right == null) {
            return true;
        }

        if (left == null || right == null) {
            return false;
        }

        if (left.val == right.val) {
            return checkLeftAndRight(left.left, right.right) && checkLeftAndRight(left.right, right.left);
        }
        return false;

    }
}
```

